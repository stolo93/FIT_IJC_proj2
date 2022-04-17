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

    htab_item_t * cur_head; 
    for (int i = 0; i < t -> arr_size; i++)
    {
        cur_head = t -> ptr[i];
        while (cur_head != NULL)
        {
            htab_erase(t, cur_head ->pair.key); //delete current record (pair)
            //always erasing the first item so the cur_head is always at t -> ptr[i]
        }
    }

    t -> size = 0;

    return;
}