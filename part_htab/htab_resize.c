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

void htab_resize(htab_t *t, size_t newn)
{
    if (newn <= 0){
        htab_free(t);
        return;
    }

    if ((size_t) newn == t -> arr_size){
        return;
    }

    //make a new table and insert all items
    htab_t * new;
    new = htab_init(newn);
    if (new == NULL){
        return;
    }
    
    new -> arr_size = newn;

    htab_item_t * cur_item;
    for (int i = 0; i < t -> arr_size; i++)
    {
        cur_item = t -> ptr[i];
        //walking the list
        while (cur_item != NULL)
        {
            htab_lookup_add(new, cur_item -> pair.key);
            cur_item = cur_item -> next;
        }
    }

    //start changing the original table
    htab_t * tmp;
    tmp = realloc(t, sizeof(htab_t) + new->arr_size * sizeof(htab_item_t *));
    if (tmp == NULL){
        htab_free(new);
        return;
    }
    t = tmp;
    
    memcpy(t, new, sizeof(htab_t) + new->arr_size * sizeof(htab_item_t *));
    htab_free(new);
    return;
}