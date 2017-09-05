#include <iostream>
using namespace :: std;
int main ()
{
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int i,j;
    int msf=0,meh=0;
    for(i=0;i<8;i++)
    {
        meh+=arr[i];
        if(meh<0)meh=0;
        if(meh>msf)msf=meh;
    }
    cout<<msf<<endl;
    return 0;
}
