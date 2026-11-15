#ifndef inv
#define inv

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE 1

typedef struct node
{
    char f_name[30];
    struct node *link;
}File_List;

int validate_inputs(char *argv[],File_List **head);
int insert_at_last(File_List **head,char *str);
int print_list(File_List **head);
#endif