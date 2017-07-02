#include <iostream>
#include <cstdio>
using namespace :: std;
int partition(int arr[],int left,int right)
{
    int key =arr[left];
    int i = left+1;
    int j = right;
    while(left<right)
    {
        while(arr[i]<=key)i++;
        while(arr[j]>=key)j--;
        if(i<j)
        {
            cout<<"BLAH";
            int t = arr[i];
            arr[i]=arr[j];
            arr[j]=t;
            i++;
            j--;
        }                
        if(i>j)break;
    }
    i--;
    int t = arr[left];
    arr[left]=arr[i];
    arr[i]=t;
    return i;
}
int main()
{   int i;
    int arr[]={5,2,3,4,1};
    int o = partition(arr,0,4);
    for(i=0;i<5;i++)cout<<arr[i]<<" ";
    cout<<endl<<o<<endl;
    return 0;
}


