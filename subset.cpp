#include<iostream>
using namespace :: std;
void sum(int i,int arr[],int cursum,int n)
{
    if(i==n){
        cout<<cursum<<endl;
        return;
    }
    else
    {
        sum(i+1,arr,cursum,n);
        sum(i+1,arr,arr[i]+cursum,n);
    }
}
int main ()
{
    int n;
    cin>>n;
    int i;
    int arr[100];
    for(i=0;i<n;i++)
        cin>>arr[i];
    sum(0,arr,0,n);
    return 0;
}
