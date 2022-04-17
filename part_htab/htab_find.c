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
#include <string.h>


htab_pair_t * htab_find(htab_t * t, htab_key_t key)
{
    if (t == NULL)
        return NULL;
    
    if (key == NULL)
        return NULL;

    htab_item_t * cur_item;
    size_t index = htab_hash_function(key) % t ->arr_size;

    cur_item = t->ptr[index];

    //walk the linked list starting at cur_item
    while (cur_item != NULL)
    {
        if (strcmp(key, cur_item -> pair.key) == 0)
        {
            return &cur_item -> pair;
        }

        cur_item = cur_item->next;
    }

    
    //only gets here in case of no match
    return NULL;
}
