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

void htab_clear(htab_t * t)
{
    if (t == NULL || t -> size == 0){ 
        return; //nothing to do 
    }

    htab_item_t * cur;
    htab_item_t * tmp;

    for (int i = 0; i < t -> arr_size; i++)
    {
        cur = t -> ptr[i];
        
        while (cur != NULL)
        {
            tmp = cur -> next;
            free((void *) cur -> pair.key);
            free(cur);

            cur = tmp;
        }
        t -> ptr[i] = NULL;
    }

    t -> size = 0;

    return;
}