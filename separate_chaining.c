#include<stdio.h>
#include<stdlib.h>
#define MAX 7
struct employee
{
    char name[20];
    int age;
    int empid;
};
struct record
{
    struct employee info;
    struct record *link;
};
int hash(int key)
{
    return (key%MAX);
}
void delete(int key,struct record *table[])
{
    int h;
    struct record *tmp,*ptr;
    h=hash(key);

    if(table[h]==NULL)
    {
        printf("key not found\n");
        return;
    }
    if(table[h]->info.empid==key)
    {
        tmp=table[h];
        table[h]=table[h]->link;
        free(tmp);
        return;
    }
    ptr=table[h];
    while(ptr->link!=NULL)
    {
        if(ptr->link->info.empid==key)
        {
            tmp=ptr->link;
            ptr->link=tmp->link;
            free(tmp);
            return;
        }
        ptr=ptr->link;
    }
    printf("key %d not found\n",key);
}
void display(struct record*table[])
{
    int i;
    struct record *ptr;

    for(i=0;i<=MAX-1;i++)
    {
        printf("\n%d-",i);
        if(table[i]!=NULL)
        {
            ptr=table[i];
            while(ptr!=NULL)
            {
                printf("%s %d %d\n",ptr->info.name,ptr->info.age,ptr->info.empid);
                ptr=ptr->link;
            }
        }
    }
}
int search(int  key,struct record *table[])
{
    int h;
    struct record *ptr;
    h=hash(key);
    ptr=table[h];
    while(ptr!=NULL)
    {
        if(ptr->info.empid==key)
        return h;
        ptr=ptr->link;
    }
    return -1;
}
void insert(struct employee emprec,struct record *table[])
{
    int h,key;
    struct record *tmp;
    key=emprec.empid;

    if(search(key,table)!=-1)
    {
        printf("duplicate key\n");
        return;
    }
    h=hash(key);

    tmp=(struct record*)malloc(sizeof(struct record));
    tmp->info=emprec;
    tmp->link=table[h];
    table[h]=tmp;
}
int main()
{
    struct record *table[MAX];
    struct employee emprec;
    int i,choice,key;

    for(i=0;i<=MAX-1;i++)
    table[i]=NULL;

    while(1)
    {
        printf("enter choice\n");
        printf("1 for insert,2 for delete\n 3 for search,4 for display\n5 for exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("enter record\n");
            scanf("%s %d %d",emprec.name,&emprec.age,&emprec.empid);
            insert(emprec,table);
            break;

            case 2:
            printf("enter key to delete\n");
            scanf("%d",&key);
            delete(key,table);
            break;

            case 3:
            printf("enter key to search\n");
            scanf("%d",&key);
            i=search(key,table);
            if(i==-1)
            printf("key not found\n");
            else
            printf("key found at chain %d",i);
            break;

            case 4:
            display(table);
            break;

            case 5:
            exit(1);

            default:
            printf("wrong choice\n");
            break;
        }
    }
}