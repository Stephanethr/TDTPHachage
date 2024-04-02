#ifndef HASHTABLE_H
#define HASHTABLE_H

// Structures de données
typedef struct {
    char* key;
    char* value;
} hsht_key_value_pair;

typedef struct {
    int size;
    int amount;
    hsht_key_value_pair **kv_items;
} hsht_hash_table;

hsht_key_value_pair* hsht_new_key_value_pair(const char* key, const char* value);
void hsht_del_key_value_pair(hsht_key_value_pair* kv_pair);
hsht_hash_table* hsht_new_hashtable(const int size);
void hsht_del(hsht_hash_table* table);
double hsht_hash(const char* string, const int alpha, const int M);

#endif /* HASHTABLE_H */