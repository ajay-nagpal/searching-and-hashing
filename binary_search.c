#include<stdio.h>
#define MAX 50

/*int binarysearch(int arr[MAX],int n,int item)
{
            int low=0,up=n-1,mid;

    while(low<=up)
    {
        mid=(low+up)/2;
        if(item<arr[mid])
        up=mid-1;
        else if(item>arr[mid])
        low=mid+1;
        else
        return mid;
    }
    return -1;
}*/

int recbinarysearch(int arr[MAX],int low,int up,int item)
{
    int mid;
    if(low>up)
    return -1;
    mid=(low+up)/2;
    if(item<arr[mid])
    recbinarysearch(arr,low,mid-1,item);
    if(item>arr[mid])
    recbinarysearch(arr,mid+1,up,item);
    else
    return mid;
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

    //int index=binarysearch(arr,n,item);
    int index=recbinarysearch(arr,0,n-1,item);
    if(index==-1)
    printf("\n not present\n");
    else 
    printf("item %d present at index %d\n",item,index);
}