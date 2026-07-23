#include<stdio.h>
int a[50],n,i,l,r,large,temp;
void heapsort(int a[],int n);
void maxheap(int a[],int n);
void heapify(int a[],int n,int i);
int main() {
    int a[50];
    int i;
    printf("Enter total number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    heapsort(a, n);
    printf("After heap sort:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

void heapsort(int a[],int n)
{
    maxheap(a,n);
    for(i=n-1;i>0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
    
    heapify(a,i,0);
}
}
void maxheap(int a[],int n)
{
    for(i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
}
void heapify(int a[],int n,int i)
{
    l=2*i+1;
    r=2*i+2;
    large=i;
    if(a[l]>a[large]&& l<n)
    {
        large = l;
    }
    if(a[r]>a[large]&& r<n)
    {
        large = r;
    }
    if(large!=i)
    {
        temp=a[large];
        a[large]=a[i];
        a[i]=temp;
    
    heapify(a,n,large);
}}
