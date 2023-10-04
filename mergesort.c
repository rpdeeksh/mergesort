#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int l, int m, int h)
{
    int i,j,k;
    int size1 = m-l+1;
    int size2 = h-m;

    int L1[size1], L2[size2];

    for(i=0;i<size1;i++)
    {
        L1[i] = arr[l+i];
    }
    for(j=0;j<size2;j++)
    {
        L2[j] = arr[m+1+j];
    }
    i=0,j=0,k=l;
    while(i< size1 && j<size2)
    {
        if(L1[i]<L2[j])
        {
            arr[k] = L1[i];
            i++;
        }
        else{
            arr[k] = L2[j];
            j++;
        }
        k++;
    }

    while(i<size1)
    {
        arr[k] = L1[i];
        i++;
        k++;
    }
    while(j<size2)
    {
        arr[k] = L2[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int l, int h)
{
    int m;
    if(l<h)
    {
        m = (l+h)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,h);
        merge(arr,l,m,h);         
    }
}
void printarray(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d, ",arr[i]);
    }
}
int main()
{
    int n;
    printf("Enter number of elements to be entered into the array : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter no %d) ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The array you entered is : ");
    printarray(arr,n);   
    
    mergesort(arr,0,n-1);

    printf("\nArray after sorting is : ");
    printarray(arr,n);
    printf("\n");
    return 0;
}