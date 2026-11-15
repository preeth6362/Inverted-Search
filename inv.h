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

typedef struct s_node
{
    char filename[30];
    int word_count;
    struct s_node *link;
}subnode_t;

typedef struct m_node
{
    char word[30];
    int file_count;
    subnode_t *s_link;
    struct m_node *link;
}mainode_t;

int validate_inputs(char *argv[],File_List **head);
int insert_at_last(File_List **head,char *str);
int print_list(File_List **head);
int create(mainode_t **arr,File_List **head);
void display(mainode_t **arr);
int search(mainode_t **arr,char *str);
int save(mainode_t **arr,char *file);
#endif