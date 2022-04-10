/**
 * @file io.c
 * @author Samuel Stolarik  (xstola03)
 * @brief 2nd part of DU2 IJC
 * 
 * @date 2022-04-10
 * 
 */

#include <stdio.h>
#include <ctype.h>


/**
 * @brief Function read one word of maximum size "max - 1"
 * and stores it to the address pointed to by "s"
 * word will be ended with \0
 * 
 * 
 * @param s 
 * @param max 
 * @param f 
 * @return int number_of_characters read
 */
int read_word(char *s, int max, FILE *f)
{
    if (f == NULL){
        fprintf(stderr, "Invalid file given.\n");
        return 0;
    }
    if (s == NULL){
        fprintf(stderr, "Adress at \"s\" is not valid.\n");
        return 0;
    }
    if (max == 0){
        return 0;
    }

    int c;
    int read_chars=0;
    while((c = getc(f)) != EOF)
    {
        if (isspace(c) && read_chars == 0){
                continue;
        } 

        else if (isspace(c) && read_chars != 0){
                break;
        }

        else
        {
            if (read_chars >= max -1){
                fprintf(stderr, "Word size limit reached.\n");
                break;
            }
            s[read_chars++] = c;
        }
    }

    if (read_chars == 0)
        return EOF;
    
    s[max - 1] = '\0';

    return read_chars;
}