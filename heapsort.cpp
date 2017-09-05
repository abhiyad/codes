#include <iostream>
#include <cstdio>
using namespace :: std ;
int size=10;
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
   int i;
  
   int arr[]={0,12,10,8,3,7,86,2,1,16,9};
    for(i=1;i<=10;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    for(i=size/2;i>=1;i--)sink(arr,i);// heap ordering
      for(i=1;i<=10;i++)
        cout<<arr[i]<<" ";  
    cout<<endl;        
    while(size)
    {
        int t= arr[1];
        arr[1]=arr[size];
        arr[size]=t;
        size--;
        sink(arr,1);
    }
   for(i=1;i<=10;i++)
        cout<<arr[i]<<" ";  
    cout<<endl;
    return 0;
}



