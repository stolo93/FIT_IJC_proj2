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

bool htab_erase(htab_t * t, htab_key_t key)
{
    size_t index = htab_hash_function(key) % t -> arr_size;
    htab_item_t * cur = t -> ptr[index];
    htab_item_t * prev = NULL;

    bool deleted = false;

    while (cur != NULL)
    {
        if (strcmp(key, cur -> pair.key) == 0){

            htab_item_t * tmp = cur -> next;
            free((void *) cur -> pair.key);
            free(cur);

            if (prev == NULL){ //in case the deleted item was the first item in the list
                t -> ptr[index] = tmp;
            }
            else {
                prev -> next = tmp;
            }
            
            t -> size -= 1; //number of pairs in the htab
            deleted = true;
            break;
        }
        prev = cur;
        cur = cur -> next;
    }
    
    //in case the tab is empty now
    if (t -> size == 0){
        htab_resize(t, t -> arr_size / 2);
    }

    else if (t -> size / t -> arr_size < AVG_LEN_MIN){
        htab_resize(t, t -> arr_size / 2);
    }

    return deleted;
}