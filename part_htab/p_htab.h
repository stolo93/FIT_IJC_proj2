/**
 * @author Samuel Stolarik (xstola03)
 * @file _htab.h
 * @date 10-04-2022
 * @brief private interface 
 * hash table structures and hashing function
 *  
 */

#include <stdint.h>
#include <stdlib.h>

#include "htab.h"


struct htab{
    int size;
    int arr_size;
    htab_pair_t * ptr[];
};

struct htab_item{
    htab_pair pair;
    htab_pair * next;
};

/**
 * @brief hashing funtion used
 * 
 * @param str 
 * @return size_t 
 */
size_t htab_hash_function(const char *str);