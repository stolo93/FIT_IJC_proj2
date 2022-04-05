/**
 * @file tail.c
 * @author Samuel Stolarik (xstola03)
 * 
 * @brief custom implementation of UNIX utility tail 
 * project 2 / part 1
 * 
 * @date 2022-04-05
 * 
 */

#include <unistd.h> 
#include <getopt.h> 
#include <stdlib.h> 
#include <stdio.h>

void set_option(int argc, char ** argv, unsigned long * req_lines);

int main(int argc, char ** argv)
{
    unsigned long req_lines;
    
    set_option(argc, argv, &req_lines);

    printf("%lu\n", req_lines);

    return 0;
}

void set_option(int argc, char ** argv, unsigned long * req_lines)
{
    char * wrong_opt = NULL;
    opterr = 0; //surpress the default error msg by getopt

    int option = getopt(argc, argv, "n");
    switch (option)
    {
    case 'n':
        if (optind > argc - 1)
        {
            //TODO error msg - optarg not given
            exit(EXIT_FAILURE);
        }
        *req_lines = strtoul(argv[optind], &wrong_opt, 10);
        if (*wrong_opt != NULL)
        {
            //TODO error msg missing optarg
            exit(EXIT_FAILURE);
        }
        break;

    case -1:
        *req_lines = 10;
        break;

    case '?':
        //TODO error msg invalid option
        exit(EXIT_FAILURE);
        break;
    }
}