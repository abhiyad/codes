#include <iostream>
using namespace :: std;
int arr[4][5] ={{1, 2, -1, -4, -20},{-8, -3, 4, 2, 1},{3, 8, 10, 1, 3},{-4, -1, 1, 7, -6}};

int sum(int l,int r,int i)
{
    int s=0;
    for(int k=l;k<=r;k++)
        s+=arr[i][k];
    return s;
}
int fun(int l,int r)
{
    int i,j;
    int meh=0,msf=0;
    for(i=0;i<4;i++)
    {
        meh+=sum(l,r,i);
        if(meh<0)meh=0;
        if(meh>msf)msf=meh;
    }
    return msf;
}
// fun returns the max value of sun between columns j=l and j=r


void kadane()
{
    int i,j;
    int max=0;
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(fun(i,j)>max)
                max=fun(i,j);
        }
    }
    cout<<max<<endl;
}



int main ()
{
    kadane();
  //  fun(0,4);
   // cout<<arr[1][3]<<endl;
    return 0;
}
                        
