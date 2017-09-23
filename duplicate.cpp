#include <iostream>
#include <cstdio>
using namespace :: std;
int main ()
{
    int arr[]={2,4,1,7,4,8,3,4};
    int i=0;
    int lt = 0, gt = 7;
    while(i<gt)
    {
        if(arr[i]==arr[lt])
            i++;
        else if(arr[i]<arr[lt])
        {
            int t = arr[i];
            arr[i]=arr[lt];
            arr[lt]=t;
            i++;
            lt++;
        }
        else
        {
            int t = arr[i];
            arr[i]=arr[gt];
            arr[gt]=t;
            gt--;
        }
    }
    for(i=0;i<8;i++)cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}



