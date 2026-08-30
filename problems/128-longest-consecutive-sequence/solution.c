#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "hash_table.h"

int longestConsecutive(int* nums, int size) {
    if (size <= 1)
        return size;

    HashTable* table = ht_create();
    for (int i = 0; i < size; i++) {
        HT_Key key = key_from_int(nums[i]);
        ht_put(table, &key, NULL);
    }

    size_t keys_count;
    HT_Key* keys = ht_get_keys(table, &keys_count);
    int longest = 0;
    for (size_t i = 0; i < keys_count; i++) {
        HT_Key prev = key_from_int(keys[i].i - 1);
        if (!ht_contains(table, &prev)) {
            int64_t current = keys[i].i;
            int count = 1;
            HT_Key next = key_from_int(current + 1);
            while (ht_contains(table, &next)) {
                current++;
                count++;
                next.i = current + 1;
            }
            if (count > longest)
                longest = count;
        }
    }
    for (size_t i = 0; i < keys_count; i++)
        key_free(&keys[i]);
    free(keys);
    ht_free(table);
    return longest;
}