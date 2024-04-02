#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

int main()
{
    hsht_hash_table *table = hsht_new_hashtable(10);
    hsht_key_value_pair *pair = hsht_new_key_value_pair("key", "value");
    hsht_key_value_pair *pair2 = hsht_new_key_value_pair("key2", "value2");
    hsht_key_value_pair *pair3 = hsht_new_key_value_pair("key3", "value3");
    hsht_key_value_pair *pair4 = hsht_new_key_value_pair("key4", "value4");
    printf("KEY: %s VALUE: %s\n", pair->key, pair->value);
    printf("KEY: %s VALUE: %s\n", pair2->key, pair2->value);
    printf("KEY: %s VALUE: %s\n", pair3->key, pair3->value);
    printf("KEY: %s VALUE: %s\n", pair4->key, pair4->value);
    printf("table: %d\n", table->size);

    printf("hash de S = abc, alpha = 397, M=10 : %lf \n", hsht_hash("abc", 397, 10));
    printf("hash de S = abcd, alpha = 397, M=10 : %lf \n", hsht_hash("abcd", 397, 10));
    printf("hash de S = paradigme, alpha = 397, M=10 : %lf \n", hsht_hash("paradigme", 397, 10));
    printf("hash de S = de, alpha = 397, M=10 : %lf \n", hsht_hash("de", 227, 53));
    printf("hash de S = est, alpha = 397, M=10 : %lf \n", hsht_hash("est", 227, 53));
    printf("hash de S = salut, alpha = 397, M=10 : %lf \n", hsht_hash("salut", 227, 53));

    hsht_del_key_value_pair(pair);
    hsht_del_key_value_pair(pair2);
    hsht_del_key_value_pair(pair3);
    hsht_del_key_value_pair(pair4);
    hsht_del(table);

    return 0;
}