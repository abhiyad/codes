#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
using namespace :: std;

struct info
{
    int d,t,s;
};
 bool sort_by_d( const info &a,const info &b)
{
    return a.d<b.d;
}  
void prgm()
{
   vector <info> vec;
   int n,days,i;
   cin>>n>>days;
   vec.resize(n);
   for(i=0;i<n;i++)
       cin>>vec[i].d>>vec[i].t>>vec[i].s;
   sort(vec.begin(),vec.end(),sort_by_d);   // that's how you sort a whole structure 
      for(i=0;i<n;i++)
       cout<<vec[i].d<<vec[i].t<<vec[i].s<<endl;

}

int main ()
{
    int t=1;
   // cin>>t;
    while(t--)
    {
        prgm();
    }
    return 0;
}
