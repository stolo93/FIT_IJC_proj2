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

size_t htab_bucket_count(const htab_t * t)
{
    if (t == NULL)
        return 0;
    
    return t -> arr_size;
}