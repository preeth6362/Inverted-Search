#include "inv.h"

int validate_inputs(char *argv[],File_List **head)
{
int i=1;
while(argv[i]!=NULL)
{
    int len=strlen(argv[i]);
    char error=0;
    if(argv[i][len-1]!='t' || argv[i][len-2]!='x' || argv[i][len-3]!='t' || argv[i][len-4]!='.')
    {
        printf("Error: %s-->Invalid file format\n",argv[i]);
        error=1;
    }
    FILE *fptr=fopen(argv[i],"r");
    if(!error && fptr==NULL)
    {
    printf("Error: %s--> File does not exist\n",argv[i]);
    error=1;
    }
    if(!error && fptr!=NULL&&fgetc(fptr)==EOF)
    {
    printf("Error: %s--> File is empty\n",argv[i]);
    error=1;
    }
    if(!error)
    {
        File_List *temp=*head;
        while(temp!=NULL)
        {
            if(strcmp(temp->f_name,argv[i])==0)
            {
            printf("Error: %s--> Duplicate file\n",argv[i]);
            error=1;
            break;
            }
            else
            temp=temp->link;
        }
    }
    if(!error)
    insert_at_last(head,argv[i]);
    i++;
}
return SUCCESS;
}

int insert_at_last(File_List **head,char *str)
{
    static File_List *tail;
    File_List *nnode=malloc(sizeof(File_List));
    strcpy(nnode->f_name,str);
    nnode->link=NULL;
    if(*head==NULL)
    {
        *head=tail=nnode;
        return SUCCESS;
    }
    tail->link=nnode;
    tail=tail->link;
    return SUCCESS;
}
int print_list(File_List **head)
{
    if(*head==NULL)return FAILURE;
    File_List *temp=*head;
    printf("Head");
    while(temp!=NULL)
    {
        printf(" ->%s",temp->f_name);
        temp=temp->link;
    }
    printf(" ->NULL\n");
    return SUCCESS;
}

int validate(char *file)
{
    int len=strlen(file);
    if(file[len-1]!='t'||file[len-2]!='x'||file[len-3]!='t'||file[len-4]!='.')
    {
    printf("Enter valid file format\n");
    return FAILURE;
    }
    FILE *fptr=fopen(file,"r");
    if(fptr==NULL)
    {
    printf("Error in opening file\n");
    return FAILURE;
    }
    if(fgetc(fptr)==EOF)
    {
    printf("Error: File is Empty\n");
    return FAILURE;
    }
    rewind(fptr);
    if(fgetc(fptr)!='#')
    {
    printf("Enter valid backup file where first and last caharcter is #\n");
    return FAILURE;
    }
    fseek(fptr,-2,SEEK_END);//becuase last character is newline
    if(fgetc(fptr)!='#')
    {
    printf("Enter valid backup file where first and last caharcter is #\n");
    return FAILURE;
    }
    fclose(fptr);
    return SUCCESS;
}