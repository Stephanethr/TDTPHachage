#include "hashtable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

hsht_key_value_pair *hsht_new_key_value_pair(const char *key, const char *value)
{
    hsht_key_value_pair *new_pair = malloc(sizeof(hsht_key_value_pair));
    new_pair->key = strdup(key);
    new_pair->value = strdup(value);
    return new_pair;
}

void hsht_del_key_value_pair(hsht_key_value_pair *kv_pair)
{
    if (kv_pair != NULL)
    {
        free(kv_pair->key);
        free(kv_pair->value);
        free(kv_pair);
    }
}

hsht_hash_table *hsht_new_hashtable(const int size)
{
    hsht_hash_table *new_table = malloc(sizeof(hsht_hash_table));
    if (new_table == NULL)
    {
        return NULL;
    }

    int table_size = (size > 0) ? size : 53;

    new_table->kv_items = calloc(table_size, sizeof(hsht_key_value_pair *));
    if (new_table->kv_items == NULL)
    {
        // Gestion de l'erreur d'allocation
        free(new_table); // Libérer la mémoire déjà allouée
        return NULL;
    }

    // Initialiser toutes les cases du tableau à NULL
    for (int i = 0; i < table_size; i++)
    {
        new_table->kv_items[i] = NULL;
    }

    // Définir la taille de la table
    new_table->size = table_size;
    new_table->amount = 0; // Initialiser le nombre d'éléments à 0

    return new_table;
}

void hsht_del(hsht_hash_table *table)
{
    if (table != NULL)
    {
        for (int i = 0; i < table->size; i++)
        {
            hsht_del_key_value_pair(table->kv_items[i]);
        }

        free(table->kv_items);

        free(table);
    }
}

double hsht_hash(const char *string, const int alpha, const int M)
{
    double indice = 0;
    int n = strlen(string);
    int ascii;
    printf("taille de la chaine de caractere : %d\n", n);
    for (int i = 0; i < n; i++)
    {
        ascii = string[i];
        printf("code ascii de la lettre %c : %d\n", string[i], ascii);
        indice += pow(alpha, i) * ascii; 
    }

    return fmod(indice, M);
}
