#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include "list.h"

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

uint64_t hash_str(const char* str);
uint64_t hash_int64(int64_t key);
uint64_t hash_key(const HT_Key* key);

HT_Key key_from_int(int64_t num);
HT_Key key_form_str(char* str);
void key_free(HT_Key* key);

HashTable* ht_create(void);
int ht_put(HashTable* table, HT_Key* key, void* value);
int ht_get(HashTable* table, HT_Key* key, void** out_value);

int ht_remove(HashTable* table, HT_Key* key);
bool ht_contains(HashTable* table, HT_Key* key);
HT_Key* ht_get_keys(HashTable* table, size_t* out_count);

#endif // HASH_TABLE_H