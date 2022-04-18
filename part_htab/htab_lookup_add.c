/**
 * @file htab_init.c
 * @author Samuel Stolarik  (xstola03)
 * @brief 2nd part of DU2 IJC
 * 
 * @date 2022-04-10
 * 
 */
#include "htab.h"
#include "p_htab.h"

#include <stdbool.h>
#include <string.h>

htab_item_t * insert_first(htab_item_t ** head, htab_key_t key);


htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key)
{
    size_t index = htab_hash_function(key) % t -> arr_size;
    htab_item_t * cur = t -> ptr[index];

    bool found = false;
    //walk the list
    while (cur != NULL)
    {
        if (strcmp(key, cur -> pair.key) == 0)
        {
            found = true;
            cur -> pair.value += 1;
            break;
        }
        cur = cur -> next;
    }

    if (found == true){
        return &cur -> pair;
    }

    htab_item_t * new = insert_first(&t -> ptr[index], key);
    if (new == NULL){
       return NULL;
    }

    t -> size += 1; //number of records in the htab
    
    if (t -> size / t -> arr_size > AVG_LEN_MAX){
        htab_resize(t, t -> arr_size * 2);
    }
    
    return &new -> pair;
}

htab_item_t * insert_first(htab_item_t ** head, htab_key_t key)
{
    if (key == NULL){
        return NULL;
    }

    htab_item_t * new = malloc(sizeof(htab_item_t));
    if (new == NULL){
        return NULL;
    }

    htab_item_t * tmp = *head;
    *head = new;
    new -> next = tmp;

    char * new_key = malloc(strlen(key));
    if (new_key == NULL){
        free(new);
        return NULL;
    }
    
    memcpy(new_key, key, strlen(key));
    new -> pair.key = new_key;
    new -> pair.value = 1;
    

    return new;
}