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
    if (t == NULL){
        return;
    }
    if (newn <= 0){
        htab_free(t);
    }
    if (newn == t -> arr_size){
        return;
    }

    htab_t * tmp = htab_init(newn);
    if (tmp == NULL){
        return;
    }

    //transfer all items into the new table with diff size
    for (int i = 0; i < t -> arr_size; i++){
        htab_item_t * cur_item = t -> ptr[i];
        
        while (cur_item != NULL)
        {
            htab_lookup_add(tmp, cur_item -> pair.key); //insert into the table once
            htab_find(tmp, cur_item -> pair.key) -> value = cur_item -> pair.value; //set the right value

            cur_item = cur_item -> next;
        }
    }

    //free old htab keys and array_ptr
    htab_clear(t);
    free(t -> ptr);

    //move new array_ptr into the old htab
    t -> ptr = tmp -> ptr;
    t -> arr_size = tmp -> arr_size;

    //delete the temporary table
    free(tmp); //not freeing tmp -> ptr because that had been assigned to the old htab   

    return;
}