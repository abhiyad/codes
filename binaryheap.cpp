#include <iostream>
#include <cstdio>
using namespace :: std ;
   int arr[]={0,2,3,4,1,6,3};  
int size=6;
void swim(int i)
{
    int p = i/2;
    while(arr[i]>arr[p] && p!=0)
    {
        int t=arr[i];
        arr[i]=arr[p];
        arr[p]=t;
        i=p;
        p=p/2;
    }
}
void sink(int arr[],int i)
{
    int m,c2,c1;
    c1=2*i+1;
    c2=2*i;          
    while(c2<=size && arr[i]<arr[c2] || c1<=size &&  arr[i]<arr[c1])
    {
        if(arr[c1]>arr[c2] && c1<=size)m=c1;
        else m=c2;  
        int t= arr[i];
        arr[i]=arr[m];
        arr[m]=t;
        i=m;
        c2=2*i;
        c1=2*i+1;
    }
    return ;
}


int main ()
{  
    sink(arr,1);
   for(int i=1;i<=size;i++)
        cout<<arr[i]<<" ";  
    cout<<endl;
    return 0;
}



