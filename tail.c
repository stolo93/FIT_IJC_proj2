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


int main(int argc, char ** argv)
{
    int option = getopt(argc, argv, "n");
    unsigned long req_lines;
    switch (option)
    {
    case 'n':
        //TODO check if number and then assign correctly
         req_lines = strtoul(argv[optind], NULL, 10);
        printf("%lu\n", req_lines);
        break;

    case -1:
        req_lines = 10;
        break;

    case '?':
        //default error msg is written by getopt
        exit(EXIT_FAILURE);
        break;
    }


    return 0;
}