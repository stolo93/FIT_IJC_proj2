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

htab_t *htab_init(size_t n){
    
    htab_t * new_tab = malloc(sizeof(htab_t));
    if (new_tab == NULL)
        return NULL;
    
    new_tab -> size = 0;
    new_tab -> arr_size = n;
    new_tab -> ptr = NULL;

    return new_tab;
}
