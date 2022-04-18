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
void print_pai(htab_pair_t * data);

int main(){

    htab_t * tab = htab_init(2);
    char word[MAX_LEN];

    while (read_word(word, MAX_LEN, stdin) != EOF)
    {
        htab_lookup_add(tab, word);
    }
    
    htab_for_each(tab, (*print_pai));

    htab_free(tab);
    return 0;
}

void print_pai(htab_pair_t * data)
{
    printf("%s \t %d\n", data -> key, data -> value);
    return;
}
