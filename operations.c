#include "inv.h"

int create(mainode_t **arr,File_List **head)
{
    File_List *temp=*head;
    int index;
    while(temp!=NULL)
    {
        FILE *fptr=fopen(temp->f_name,"r");
        if(fptr==NULL)return FAILURE;
        char buff[30];
        while(fscanf(fptr,"%s",buff)!=EOF)
        {
            if(buff[0]>='a'&&buff[0]<='z')
            index=buff[0]-'a';
            else if(buff[0]>='A'&&buff[0]<='Z')
            index=buff[0]-'A';
            else index=26;
            if(arr[index]==NULL)
            {
                mainode_t *mnode=malloc(sizeof(mainode_t));
                strcpy(mnode->word,buff);
                mnode->file_count=1;
                mnode->link=NULL;
                mnode->s_link=NULL;
                subnode_t *snode=malloc(sizeof(subnode_t));
                snode->word_count=1;
                strcpy(snode->filename,temp->f_name);
                snode->link=NULL;
                arr[index]=mnode;
                mnode->s_link=snode;
            }
            else
            {
                mainode_t *mtemp=arr[index],*mlast;
                while(mtemp!=NULL)
                {
                    if(strcmp(buff,mtemp->word)==0)
                    {
                        subnode_t *stemp=mtemp->s_link,*slast;
                        while(stemp!=NULL)
                        {
                            if(strcmp(stemp->filename,temp->f_name)==0)
                            {
                                stemp->word_count++;
                                break;
                            }
                            else
                            {
                            slast=stemp;
                            stemp=stemp->link;
                            }
                        }
                        if(stemp==NULL)
                        {
                            subnode_t *snode=malloc(sizeof(subnode_t));
                            snode->word_count=1;
                            strcpy(snode->filename,temp->f_name);
                            snode->link=NULL;
                            mtemp->file_count++;
                            slast->link=snode;
                        }
                        break;
                    }
                    else
                    {
                        mlast=mtemp;
                        mtemp=mtemp->link;
                    }
                }
                if(mtemp==NULL)
                {
                mainode_t *mnode=malloc(sizeof(mainode_t));
                strcpy(mnode->word,buff);
                mnode->file_count=1;
                mnode->link=NULL;
                mnode->s_link=NULL;
                subnode_t *snode=malloc(sizeof(subnode_t));
                snode->word_count=1;
                strcpy(snode->filename,temp->f_name);
                snode->link=NULL;
                mlast->link=mnode;
                mnode->s_link=snode;
                }
            }
        }
        temp=temp->link;
    }
    return SUCCESS;
}

void display(mainode_t **arr)
{
    printf("Index\tWord\t\tFilecount\tFilename\tWordCound\n");
    for(int i=0;i<27;i++)
    {
        printf("%d\t",i);
        mainode_t *mtemp=arr[i];
        while(mtemp!=NULL)
        {
            if(mtemp==arr[i])
            printf("%s\t\t",mtemp->word);
           else
           printf("\t%s\t\t",mtemp->word);
            printf("%d\t\t",mtemp->file_count);
            subnode_t *stemp=mtemp->s_link;
            while(stemp!=NULL)
            {
                printf("%s\t",stemp->filename);
                printf("%d\n",stemp->word_count);
                stemp=stemp->link;
            }
            mtemp=mtemp->link;
        }
        printf("\n");
    }
}
