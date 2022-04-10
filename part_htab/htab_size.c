/**
 * @file htab_init.c
 * @author Samuel Stolarik  (xstola03)
 * @brief 2nd part of DU2 IJC
 * return number of records in hash table
 * 
 * @date 2022-04-10
 * 
 */

#include "htab.h"
#include "p_htab.h"

size_t htab_size(const htab_t * t)
{
    if (t == NULL)
        return -1;
    
    return t -> arr_size;
}