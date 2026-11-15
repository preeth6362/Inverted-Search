#include "inv.h"

int search(mainode_t **arr,char *str)
{
    int index;
    if(str[0]>='a'&&str[0]<='z')
    index=str[0]-'a';
    else if(str[0]>='A'&&str[0]<='Z')
    index=str[0]-'A';
    else index=26;
    if(arr[index]==NULL)
    {
        return FAILURE;
    }
    mainode_t *mtemp=arr[index];
    while(mtemp!=NULL)
    {
        if(strcmp(mtemp->word,str)==0)
        {
            printf("Word %s is present in %d files\n",mtemp->word,mtemp->file_count);
            subnode_t *stemp=mtemp->s_link;
            while(stemp!=NULL)
            {
                printf("In %s => %d times\n",stemp->filename,stemp->word_count);
                stemp=stemp->link;
            }
            break;
        }
        else
        mtemp=mtemp->link;
    }
    if(mtemp==NULL)
    return FAILURE;
else
return SUCCESS;
}

int save(mainode_t **arr,char *file)
{
    FILE *fptr=fopen(file,"w");
    if(fptr==NULL)return FAILURE;
    for(int i=0;i<27;i++)
    {
        mainode_t *mtemp=arr[i];
        while(mtemp!=NULL)
        {
            fprintf(fptr,"#%d;%s;%d;",i,mtemp->word,mtemp->file_count);
            subnode_t *stemp=mtemp->s_link;
            while(stemp!=NULL)
            {
                fprintf(fptr,"%s;%d;",stemp->filename,stemp->word_count);
                stemp=stemp->link;
            }
            fprintf(fptr,"#\n");
            mtemp=mtemp->link;
        }
    }
    return SUCCESS;
}