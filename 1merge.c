#include<stdio.h>
void main()
{
int ar1[20],ar2[20],ar3[40];
int m,n;
void read_array(int[],int);
void print_array(int[],int);
void merge(int[],int[],int[],int,int);
printf("no of elements in first array[1-20]:");
scanf("%d",&m);
printf("Enter the elements in non decreasing order:");
read_array(ar1,m);
printf("No of elements in second array:");
scanf("%d",&n);
printf("enter elements in non decreasing order:");
read_array(ar2,n);
merge(ar1,ar2,ar3,m,n);
printf("Merged array:\n");
print_array(ar3,m+n);
}
void read_array(int ar[],int m)   //function for reading an array
{
int i;
for(i=0;i<m;i++)
scanf("%d",&ar[i]);
return;
}
void print_array(int ar[],int n)  //function for printing an array
{
int i;
for(i=0;i<n;i++)
printf("%d ",ar[i]);
return;
}
void merge(int a[],int b[],int c[],int m,int n)  //function for merging two arrays
{
int i,j,k;
i=j=k=0;
while(i<m && j<n)  //compare and copy elements
if(a[i]<b[j])
{
c[k]=a[i];
i=i+1;
k=k+1;
}
else
{
c[k]=b[j];
j=j+1;
k=k+1;
}
while(i<m)  //copy remaining elements if any from array 'a'
c[k++]=a[i++];
while(j<n)  //copy remaining elements if any from array 'b'
c[k++]=b[j++];
}  //end of merge

