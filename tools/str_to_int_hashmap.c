#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


static const int prime_sizes[] = {
    5, 11, 23, 47, 97, 197, 397, 797, 1597, 3203, 6421,
    12853, 25717, 51437, 102877, 205759, 411527, 823117,
    1646237, 3292489, 6584983, 13169977, 26339969, 52679969,
    105359939, 210719881, 421439783, 842879579, 1685759167
};

static const int prime_sizes_count = sizeof(prime_sizes) / sizeof(prime_sizes[0]);

typedef struct node {
    char* key;
    int value;
    struct node* next;
} node;

typedef struct hash_map {
    node** buckets;
    int sizes_idx;
    int buckets_count;
    int count;
} hash_map;

unsigned long hash_str(const char* str)
{
    if (str == NULL)
        return 0;
    unsigned long hash = 5381;
    unsigned char c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + (unsigned long)c;
    }
    return hash;
}

hash_map* hashmap_create(void)
{
    hash_map* map = (hash_map*)malloc(sizeof(hash_map));
    if (map == NULL)
        return NULL;
    map->sizes_idx = 0;
    map->buckets_count = prime_sizes[map->sizes_idx];
    map->buckets = calloc(map->buckets_count, sizeof(node*));
    if (map->buckets == NULL) {
        free(map);
        return NULL;
    }
    map->count = 0;

    return map;
}

void hashmap_resize(hash_map* map)
{
    if (map == NULL)
        return;

    if (map->sizes_idx + 1 >= prime_sizes_count)
        return;

    int old_buckets_count = prime_sizes[map->sizes_idx];
    map->sizes_idx++;
    int new_buckets_count = prime_sizes[map->sizes_idx];
    node** new_buckets = calloc(new_buckets_count, sizeof(node*));

    if (new_buckets == NULL) {
        map->sizes_idx--;
        return;
    }

    for (int i = 0; i < old_buckets_count; i++) {
        node* current = map->buckets[i];

        while (current != NULL) {
            node* next = current->next;

            int new_idx = hash_str(current->key) % new_buckets_count;
            current->next = new_buckets[new_idx];
            new_buckets[new_idx] = current;

            current = next;
        }
    }

    free(map->buckets);
    map->buckets = new_buckets;
    map->buckets_count = new_buckets_count;
}

bool hashmap_get(hash_map* map, const char* key, int* value)
{
    if (map == NULL || key == NULL || value == NULL)
        return false;

    int idx = hash_str(key) % map->buckets_count;
    node* entry = map->buckets[idx];

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            *value = entry->value;
            return true;
        }
        entry = entry->next;
    }
    return false;
}

bool hashmap_put(hash_map* map, const char* key, int value)
{
    if (map == NULL || key == NULL)
        return false;

    if ((double)map->count / (double)map->buckets_count > 0.75)
        hashmap_resize(map);

    int idx = hash_str(key) % map->buckets_count;
    node* entry = map->buckets[idx];

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;
            return true;
        }
        entry = entry->next;
    }


    node* new_entry = malloc(sizeof(node));
    if (new_entry == NULL) {
        return false;
    }
    char* new_key = malloc(strlen(key) + 1);
    if (new_key == NULL) {
        free(new_entry);
        return false;
    }
    strcpy(new_key, key);
    new_entry->key = new_key;
    new_entry->value = value;
    new_entry->next = map->buckets[idx];
    map->buckets[idx] = new_entry;
    map->count++;

    return true;
}

void hashmap_remove(hash_map* map, const char* key)
{
    if (map == NULL || key == NULL)
        return;

    int idx = hash_str(key) % map->buckets_count;
    node* entry = map->buckets[idx];
    node* prev = NULL;

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            if (prev)
                prev->next = entry->next;
            else
                map->buckets[idx] = entry->next;

            free(entry->key);
            free(entry);
            map->count--;
            return;

        }
        prev = entry;
        entry = entry->next;
    }
}

void hashmap_free(hash_map* map)
{
    if (map == NULL)
        return;

    for (int i = 0; i < map->buckets_count; i++) {
        node *entry = map->buckets[i];
        while (entry != NULL) {
            node *next = entry->next;
            free(entry->key);
            free(entry);
            entry = next;
        }
    }
    free(map->buckets);
    free(map);
}