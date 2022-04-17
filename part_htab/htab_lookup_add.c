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

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key)
{
    size_t index = htab_hash_function(key) % t -> arr_size;
    htab_item_t * cur = t -> ptr[index];

    size_t count = 0;
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
        count++;
        cur = cur -> next;
    }

    if (found == true){
        return &cur -> pair;
    }

   htab_item_t * new = insert_after(cur, key);
   if (new == NULL){
       return NULL;
   }

   count++;
   if (count >= AVG_LEN_MAX){
       htab_resize(t, t -> arr_size * 2);
   }
   
   return &new -> pair;
}

htab_item_t * insert_after(htab_item_t * cur_item, htab_key_t key)
{
    if (key == NULL){
        retrun NULL;
    }

    htab_item_t * new = malloc(sizeof(htab_item_t));
    if (new == NULL){
        return NULL;
    }

    new -> next = cur_item ->next;
    new ->pair.key = key;
    new ->pair.value = 1;

    cur_item -> next = new;

    return new;
}