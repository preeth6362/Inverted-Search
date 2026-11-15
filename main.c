#include "inv.h"

int main(int argc,char *argv[])
{
    File_List *head=NULL;
    mainode_t *arr[27]={NULL};

    if(argc==1)
    {
        printf("Error: insufficient arguments\n");
        return 0;
    }
    validate_inputs(argv,&head);
    print_list(&head);

    int choice;
    do{
    printf("Select the operation\n1. Create Database\n2.Display Database\n3. Search Database\n4. Update Database\n5. Save DataBase\n6.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            if(create(arr,&head)==SUCCESS)
            printf("Database created succeessfully\n");
            else
            printf("Error creating Database\n");
        break;
        }
        case 2:
        {
            display(arr);
            break;
        }
        case 3:
        {
            char inp[30];
            printf("Enter the word you want to search: ");
            scanf("%s",inp);
            if(search(arr,inp)==FAILURE)
            printf("Word not found\n");
            break;
        }
        case 5:
        {
            char file[30];
            printf("Enter the filename: ");
            scanf("%s",file);
            int len=strlen(file);
            if(file[len-1]!='t' || file[len-2]!='x' || file[len-3]!='t' || file[len-4]!='.')
            {    
             printf("Error: %s-->Invalid file format\n",file);
             break;
            }
            if(save(arr,file)==SUCCESS)
            printf("Database saved successfully\n");
        break;
        }
        case 6:
        break;
    }
   }while(choice!=6);
}