/**
 * @file htab_init.c
 * @author Samuel Stolarik  (xstola03)
 * @brief 2nd part of DU2 IJC
 * implementation of hash table constructor
 * 
 * @date 2022-04-10
 * 
 */

#include "htab.h"
#include "p_htab.h"

htab_t *htab_init(size_t n){
    
    if (n <= 0) 
        return NULL;
        
    htab_t * new_tab = malloc(sizeof(htab_t) + n * sizeof(htab_item_t *));
    if (new_tab == NULL)
        return NULL;
    
    new_tab -> size = 0;
    new_tab -> arr_size = n;

    for (size_t i = 0; i < n; i++)
    {
        new_tab -> ptr[i] = NULL;
    }
    
    return new_tab;
}
