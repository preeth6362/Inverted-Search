#include "inv.h"

int main(int argc,char *argv[])
{
    File_List *head=NULL;
    if(argc==1)
    {
        printf("Error: insufficient arguments\n");
        return 0;
    }
    validate_inputs(argv,&head);
    print_list(&head);
}