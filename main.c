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
        case 6:
        break;
    }
   }while(choice!=6);
}