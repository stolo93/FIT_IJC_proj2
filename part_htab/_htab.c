/**
 * @author Samuel Stolarik (xstola03)
 * @file _htab.h
 * @date 10-04-2022
 * @brief hash table structure and hashing function
 *  
 */

#include <stdint.h>
#include <stdlib.h>

#include "htab.h"


struct htab{
    int size;
    int arr_size;
    htab_pair_t * ptr;
};

/**
 * @brief hashing funtion used
 * 
 * @param str 
 * @return size_t 
 */
size_t htab_hash_function(const char *str) {
    uint32_t h=0;     // musí mít 32 bitů
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
    }


