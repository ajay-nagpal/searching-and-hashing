#include<stdio.h>
#define MAX 50
/*int search(int arr[MAX],int n,int item)
{
    int i=0;
    while(i<n&&item!=arr[i])
    i++;
    if(i<n)
    return i;
    else 
    return -1;
}*/
/*int search(int arr[MAX],int n,int item)
{
    int i=0;
    while(item!=arr[i])
    i++;
    if(i<n)
    return i;
    else 
    return -1;
}*/
int searchinsortedarray(int arr[MAX],int n,int item)
{
    int i=0;
    while(i<n&&arr[i]<item)
    i++;
    if(arr[i]==item)
    return i;
    else 
    return -1;
}
int main()
{
    int n,i,arr[MAX],item;
    printf("enter nmber of elements\n");
    scanf("%d",&n);

    printf("enter elements \n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    printf("enter item to seach\n");
    scanf("%d",&item);

    //int index=search(arr,n,item);
    int index=searchinsortedarray(arr,n,item);
    if(index==-1)
    printf("\n not present\n");
    else 
    printf("item %d present at index %d\n",item,index);
}