#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

static const size_t prime_sizes[] = {
    5, 11, 23, 47, 97, 197, 397, 797, 1597, 3203, 6421,
    12853, 25717, 51437, 102877, 205759, 411527, 823117,
    1646237, 3292489, 6584983, 13169977, 26339969, 52679969,
    105359939, 210719881, 421439783, 842879579, 1685759167
};

static const size_t primes_count = sizeof(prime_sizes) / sizeof(prime_sizes[0]);

typedef enum {
    KEY_INT,
    KEY_STR
} HT_KeyType;

typedef struct {
    HT_KeyType type;
    union {
        int64_t i;
        char* s;
    };
} HT_Key;

typedef struct {
    HT_Key key;
    void* value;
} HT_Pair;


typedef struct {
    List** buckets;
    int sizes_idx;
    size_t buckets_count;
    size_t count;
} HashTable;

uint64_t hash_str(const char* str)
{
    uint64_t hash = 5381;
    while (*str != '\0') {
        hash = ((hash << 5) + hash) + (unsigned char)*str;
        str++;
    }
    return hash;
}

uint64_t hash_int64(int64_t key)
{
    uint64_t x = (uint64_t)key;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    x = x ^ (x >> 31);
    return x;
}

uint64_t hash_key(const HT_Key* key)
{
    if (key->type == KEY_INT)
        return hash_int64(key->i);
    return hash_str(key->s);
}

static bool key_equal(HT_Key* key1, HT_Key* key2)
{
    if (key1 == NULL || key2 == NULL)
        return false;

    if (key1->type == key2->type) {
        switch (key1->type) {
            case KEY_INT:
                return key1->i == key2->i;
            case KEY_STR:
                return strcmp(key1->s, key2->s) == 0;
            default:
                return false;
        }
    }
    return false;
}

HT_Key key_from_int(int64_t num)
{
    HT_Key key;
    key.type = KEY_INT;
    key.i = num;
    return key;
}

HT_Key key_form_str(char* str)
{
    HT_Key key;
    key.type = KEY_STR;
    key.s = str;
    return key;
}

void key_free(HT_Key* key)
{
    if (key == NULL)
        return;

    if (key->type == KEY_STR) {
        free(key->s);
        key->s = NULL;
    }
}

static int key_dup(HT_Key* dst, HT_Key* src)
{
    switch (src->type) {
        case KEY_INT:
            dst->type = KEY_INT;
            dst->i = src->i;
            return 0;
        case KEY_STR: {
            size_t str_size = strlen(src->s) + 1;
            char* str = malloc(str_size);
            if (str == NULL)
                return 1;
            memcpy(str, src->s, str_size);
            dst->type = KEY_STR;
            dst->s = str;
            return 0;
        }
        default:
            fprintf(stderr, "key_dup: unknown key type %d\n", src->type);
            abort();
    }
}

static int ht_buckets_init(List** buckets, size_t count)
{
    if (buckets == NULL)
        return 1;
    for (size_t i = 0; i < count; i++) {
        buckets[i] = list_create();

        if (buckets[i] == NULL) {
            goto cleanup;
        }
    }
    return 0;

cleanup:
    for (size_t i = 0; i < count; i++) {
        if (buckets[i] != NULL) {
            list_free(buckets[i]);
            buckets[i] = NULL;
        }
    }
    return 1;
}

HashTable* ht_create(void)
{
    HashTable* table = malloc(sizeof(HashTable));
    if (table == NULL)
        return NULL;

    table->sizes_idx = 0;
    table->buckets_count = prime_sizes[table->sizes_idx];
    table->buckets = calloc(table->buckets_count, sizeof(List*));
    if (table->buckets == NULL) {
        free(table);
        return NULL;
    }

    if (ht_buckets_init(table->buckets, table->buckets_count) != 0) {
        free(table->buckets);
        free(table);
        return NULL;
    }
    table->count = 0;

    return table;
}

int ht_resize(HashTable* table)
{
    if (table == NULL)
        return 1;

    if ((size_t)table->sizes_idx + 1 >= primes_count)
        return 1;

    size_t new_count = prime_sizes[table->sizes_idx + 1];
    List** new_buckets = calloc(new_count, sizeof(List*));
    if (new_buckets == NULL)
        return 1;

    if (ht_buckets_init(new_buckets, new_count) != 0) {
        free(new_buckets);
        return 1;
    }

    for (size_t i = 0; i < table->buckets_count; i++) {
        List* bucket = table->buckets[i];
        ListIterator* it = list_iterator_create(bucket);
        if (it == NULL) {
            for (size_t j = 0; j < new_count; j++)
                list_free(new_buckets[j]);
            free(new_buckets);
            return 1;
        }

        while (list_iterator_has_next(it)) {
            HT_Pair* pair = (HT_Pair*)list_iterator_next(it, NULL);
            uint64_t hash = hash_key(&pair->key);
            List* new_bucket = new_buckets[hash % new_count];
            if (list_push_back(new_bucket, pair, sizeof(HT_Pair)) != 0) {
                list_iterator_free(it);
                for (size_t j = 0; j < new_count; j++)
                    list_free(new_buckets[j]);
                free(new_buckets);
                return 1;
            }
        }
        list_iterator_free(it);
        list_free(bucket);
    }

    free(table->buckets);
    table->buckets = new_buckets;
    table->buckets_count = new_count;
    table->sizes_idx++;

    return 0;
}

long ht_find_in_bucket(List* bucket, HT_Key* key)
{
    ListIterator* it = list_iterator_create(bucket);
    if (it == NULL)
        return -1;

    long idx = 0;
    while (list_iterator_has_next(it)) {
        void* data = list_iterator_next(it, NULL);
        HT_Pair* pair = (HT_Pair*)data;
        if (key_equal(&pair->key, key)) {
            list_iterator_free(it);
            return idx;
        }
        idx++;
    }
    list_iterator_free(it);
    return -1;
}

int ht_put(HashTable* table, HT_Key* key, void* value)
{
    if (table == NULL || key == NULL)
        return 1;

    if ((double)table->count / (double)table->buckets_count >= 0.75)
        ht_resize(table);

    uint64_t hash = hash_key(key);
    List* bucket = table->buckets[hash % table->buckets_count];

    HT_Pair pair;
    if (key_dup(&pair.key, key) != 0)
        return 1;    
    pair.value = value;
    long key_idx = ht_find_in_bucket(bucket, key);

    if (key_idx >= 0) {
        if (list_set_at(bucket, key_idx, &pair, sizeof(HT_Pair)) != 0) {
            return 1;
        }
    }
    else {
        if (list_push_back(bucket, &pair, sizeof(HT_Pair)) != 0) {
            return 1;
        }
        table->count++;
    }
    return 0;
}

int ht_get(HashTable* table, HT_Key* key, void** out_value)
{
    if (table == NULL || key == NULL || out_value == NULL)
        return 1;

    uint64_t hash = hash_key(key);
    List* bucket = table->buckets[hash % table->buckets_count];

    long idx = ht_find_in_bucket(bucket, key);
    if (idx < 0)
        return 1;

    HT_Pair pair;
    if (list_get_at(bucket, (size_t)idx, &pair) != 0)
        return 1;

    *out_value = pair.value;
    return 0;
}

int ht_remove(HashTable* table, HT_Key* key)
{
    if (table == NULL || key == NULL)
        return 1;

    uint64_t hash = hash_key(key);
    List* bucket = table->buckets[hash % table->buckets_count];

    long idx = ht_find_in_bucket(bucket, key);
    if (idx < 0)
        return 1;

    HT_Pair pair;
    if (list_get_at(bucket, (size_t)idx, &pair) != 0)
        return 1;

    key_free(&pair.key);

    if (list_remove_at(bucket, (size_t)idx) != 0)
        return 1;

    table->count--;
    return 0;
}


bool ht_contains(HashTable* table, HT_Key* key)
{
    if (table == NULL || key == NULL)
        return false;

    uint64_t hash = hash_key(key);
    List* bucket = table->buckets[hash % table->buckets_count];

    return ht_find_in_bucket(bucket, key) >= 0;
}

void ht_free(HashTable* table)
{
    if (table == NULL)
        return;

    for (size_t i = 0; i < table->buckets_count; i++) {
        List* bucket = table->buckets[i];
        if (bucket == NULL)
            continue;

        ListIterator* it = list_iterator_create(bucket);
        if (it != NULL) {
            while (list_iterator_has_next(it)) {
                HT_Pair* pair = (HT_Pair*)list_iterator_next(it, NULL);
                key_free(&pair->key);
            }
            list_iterator_free(it);
        }
        list_free(bucket);
    }

    free(table->buckets);
    free(table);
}

HT_Key* ht_get_keys(HashTable* table, size_t* out_count)
{
    if (table == NULL || out_count == NULL)
        return NULL;

    HT_Key* keys = malloc(table->count * sizeof(HT_Key));
    if (keys == NULL)
        return NULL;

    size_t k = 0;
    for (size_t i = 0; i < table->buckets_count; i++) {
        List* bucket = table->buckets[i];
        ListIterator* it = list_iterator_create(bucket);
        if (it == NULL) {
            for (size_t j = 0; j < k; j++)
                key_free(&keys[j]);
            free(keys);
            return NULL;
        }

        while (list_iterator_has_next(it)) {
            HT_Pair* pair = (HT_Pair*)list_iterator_next(it, NULL);
            if (key_dup(&keys[k], &pair->key) != 0) {
                list_iterator_free(it);
                for (size_t j = 0; j < k; j++)
                    key_free(&keys[j]);
                free(keys);
                return NULL;
            }
            k++;
        }
        list_iterator_free(it);
    }

    *out_count = table->count;
    return keys;
}
// END