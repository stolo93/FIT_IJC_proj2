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

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data))
{
    if (t == NULL || f == NULL){
        return;
    }

    htab_item_t * cur;
    for (int i = 0; i < t -> arr_size; i++)
    {
        cur = t -> ptr[i];

        while (cur != NULL)
        {
            f(&cur ->pair);

            cur = cur -> next;
        }
    }

    return;
}