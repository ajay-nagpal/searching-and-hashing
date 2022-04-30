#include<stdio.h>
#include<stdlib.h>
#define MAX 5
enum type_of_record{empty,deleted,occupied};
struct employee
{
    char name[20];
    int age;
    int empid;
};
struct record
{
    struct employee info;
    enum type_of_record status;
};
int hash(int key)
{
    return(key%MAX);
}
void display(struct record table[])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        printf("%d\t",i);
        if(table[i].status==occupied)
            printf("occupied\n %s , %d  , %d\n",table[i].info.name,table[i].info.age,table[i].info.empid);
        else if(table[i].status==deleted)
        printf("key deleted\n");
        else
        printf("empty\n");
    }
}
int searchkey(int key,struct record table[])
{
    int i,h,location;
    h=hash(key);
    location=h;

    for(i=1;i!=MAX-1;i++)
    {

        if(table[location].status==empty)
        return -1;
        if(table[location].info.empid==key)
        return location;
    
        location=(h+i)%MAX;
    }
    return -1;
}
void delete(int key,struct record table[])
{
    int location=searchkey(key,table);

    if(location==-1)
    printf("keyn not found\n");
    else
    table[location].status=deleted;
}

void insert (struct employee emprec,struct record table[])
{
    int i,location,h;
    int key=emprec.empid;
    h=hash(key);
    location=h;

    for(i=1;i!=MAX-1;i++)
    {
        if(table[location].status==empty||table[location].status==deleted)
        {
            table[location].info=emprec;
            table[location].status=occupied;
            printf("record inserted\n");
            return;
        }
        if(table[location].info.empid==key)
        {
            printf("duplicate key\n");
            return;
        }
        location=(h+i)%MAX;
    }
    printf("cant insert overflow\n");
}
int main()
{
    int i,key,choice;
    struct record table[MAX];
    struct employee emprec;
    for(i=0;i<MAX;i++)
        table[i].status=empty;

    while(1)
    {
        printf("enter choice \n");
        printf("1 for insert ,2 for delete\n");
        printf("3 for search,4 for display,5 for exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("enter name ,age,empid\n");
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
            i=searchkey(key,table);
            if(i==-1)
            printf("key not found\n");
            else
             printf("key  at index %d ",i);
            break;

            case 4:
            display(table);
            break; 
            
            case 5:
            exit(1);

            default:
            printf("wrong choice\n");
        }
        
    }
}