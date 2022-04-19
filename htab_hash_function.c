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

#include <stdlib.h>

#ifndef HASHTEST
//hashing function given in the assignment
size_t htab_hash_function(const char *str)
{
    uint32_t h=0;     // musí mít 32 bitů
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}

#else
//hashing function for testing
//source: http://www.cse.yorku.ca/~oz/hash.html variant djb2
size_t htab_hash_function(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *(const unsigned char*)str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

//the use of this function proved to be a bit faster while testing
//used input: seq 1000000 2000000|shuf
//avg time: 1,2 s faster than the first function 
#endif
