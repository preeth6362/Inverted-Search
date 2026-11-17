#include "inv.h"

extern char create_flag;

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
        fclose(fptr);
        temp=temp->link;
    }
    create_flag=1;
    return SUCCESS;
}

void display(mainode_t **arr)
{
    printf("%-8s%-20s%-12s%-20s%-10s\n","Index","Word","Filecount","Filename","WordCount");
    for(int i=0;i<27;i++)
    {
        printf("%-8d",i);
        mainode_t *mtemp=arr[i];
        while(mtemp!=NULL)
        {
            if(mtemp==arr[i])
            printf("%-20s",mtemp->word);
           else
           printf("%-8s%-20s"," ",mtemp->word);
            printf("%-12d",mtemp->file_count);
            subnode_t *stemp=mtemp->s_link;
            while(stemp!=NULL)
            {
                if(stemp==mtemp->s_link)
                printf("%-20s",stemp->filename);
                else
                printf("%-8s%-20s%-12s%-20s"," "," "," ",stemp->filename);
                printf("%-10d\n",stemp->word_count);
                stemp=stemp->link;
            }
            mtemp=mtemp->link;
        }
        printf("\n");
    }
}
