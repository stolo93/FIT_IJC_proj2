/**
 * @file htab_init.c
 * @author Samuel Stolarik  (xstola03)
 * @brief 2nd part of DU2 IJC
 * 
 * @date 2022-04-10
 * 
 */
#include "htab.h"

#include <stdio.h>

#define MAX_LEN 4096
#define SIZE_START 40

extern int read_word(char *s, int max, FILE *f);

int main(){

    htab_t * tab = htab_init(5);
    char word[MAX_LEN] = {0};

    while (read_word(word, MAX_LEN, stdin) != EOF)
    {
        htab_pair_t * tmp = htab_lookup_add(tab, word);
        printf("%d\n", tmp ->value);
    }

    htab_free(tab);
    return 0;
}