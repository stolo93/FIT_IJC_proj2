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
#include <string.h>

#define MAX_CHARS 4096 //size of the line (counting newline and zero byte at the end)

#define er_print(msg) fprintf(stderr, msg)

//function prototypes

void set_option(int argc, char ** argv, unsigned long * req_lines, int * next_arg);
void push_back(char * buffer,int buf_size, char ** storage, unsigned long size);
void print_lines(char ** lines, unsigned long size);

typedef unsigned long ulong;


//------------MAIN FUNCTION----------
int main(int argc, char ** argv)
{
    ulong req_lines;
    int file_ind;
    set_option(argc, argv, &req_lines, &file_ind);

    FILE * fin;

    if (argv[file_ind] == NULL){
        fin = stdin;
    }
    else {
        fin = fopen(argv[file_ind], "r");
        if (fin == NULL){
            er_print("File was not opened succesfully.\n");
            goto error_handling1;
        }
    }
    
    //prepare storage for lines
    char ** last_lines = malloc(sizeof(char *) * req_lines);
    if (last_lines == NULL){
        er_print("Malloc failed.\n");
        goto error_handling2;
    }

    ulong allocated;
    for (ulong allocated = 0; allocated < req_lines; allocated++)
    {
        last_lines[allocated] = calloc(MAX_CHARS, sizeof(char));
        if (last_lines[allocated] == NULL){
            er_print("Malloc failed.\n");
            goto error_handling3;
        }
    }

    //read and store lines
    char buffer[MAX_CHARS] = {0};
    while (fgets(buffer, MAX_CHARS - 1, fin) != NULL)
    {
        //if the whole line doesn't fit into the buffer, add newline at the end of the buffer and read
        // all characters until end of line is read (to ignore it)
        if (strchr(buffer, '\n') == NULL)
        {
            fprintf(stderr, "Limit of %d characters per line exceeded.\n", MAX_CHARS - 1);
            buffer[MAX_CHARS - 2] = '\n';
            int c;
            while ((c = getc(fin)) != '\n')
            ;
        }
        push_back(buffer, MAX_CHARS, last_lines, req_lines);
    }

    print_lines(last_lines, req_lines);

    for (ulong i = 0; i < allocated; i++){
        free(last_lines[i]);
    }
    free(last_lines);

    fclose(fin);
    return EXIT_SUCCESS;

    //free everything in case of error
    error_handling3:
    //freeing only number of lines that was allocated in the first place
    for (ulong i = 0; i < allocated; i++){
        free(last_lines[i]);
    }

    error_handling2:
    free(last_lines);

    error_handling1:
    fclose(fin);
    return EXIT_FAILURE;
}


/**
 * @brief insert value to the array and keep its lenght by deleting the last item
 * 
 * @param buffer 
 * @param storage 
 * @param size 
 */
void push_back(char * buffer,int buf_size, char ** storage, unsigned long size)
{
    char tmp[buf_size];
    char tmp_buf[buf_size];
    memcpy(tmp_buf, buffer, buf_size);

    for (int i = size - 1; i >= 0; i--)
    {
        memcpy(tmp, storage[i], buf_size);
        memcpy(storage[i], tmp_buf, buf_size);
        memcpy(tmp_buf, tmp, buf_size);
    }

    return;
}


/**
 * @brief print number of "size" lines from "lines"
 * 
 * @param lines 
 * @param size 
 */
void print_lines(char ** lines, unsigned long size)
{
    for (unsigned long i = 0; i < size; i++)
    {
        printf("%s", lines[i]);
    }

    return;
}

/**
 * @brief set the command line option of requested lines, if no special option was given
 * the unsigned long pointed to by req_lines is set to default value, which is 10
 * 
 * if the option is wrong or the option argument is missing program is exited with EXIT_FAILURE value
 * @param argc 
 * @param argv 
 * @param req_lines 
 * @param next_arg 
 */
void set_option(int argc, char ** argv, unsigned long * req_lines, int * next_arg)
{
    char * wrong_opt = NULL;
    opterr = 0; //surpress the default error msg by getopt

    int option = getopt(argc, argv, "n");
    switch (option)
    {
    case 'n':
        if (optind > argc - 1)
        {
            er_print("Option argument not given.\n");
            exit(EXIT_FAILURE);
        }

        *req_lines = strtoul(argv[optind], &wrong_opt, 10);
        *next_arg = optind + 1;

        if (*wrong_opt != '\0')
        {  
            er_print("Option argument must be a positive integer number.\n");
            exit(EXIT_FAILURE);
        }
        break;

    case -1:
        *req_lines = 10;
        *next_arg = optind;
        break;

    case '?':
        er_print("Invalid option given.\n");
        exit(EXIT_FAILURE);
        break;
    }

    return;
}