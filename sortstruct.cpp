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
 bool sort_by_s( const info &a,const info &b)
{
    return (a.s>b.s) ;
}  
void prgm()
{
   vector <info> vec;
   int n,days,i;
   cin>>n>>days;
   vec.resize(n);
   for(i=0;i<n;i++)
       cin>>vec[i].d>>vec[i].t>>vec[i].s;
   sort(vec.begin(),vec.end(),sort_by_s);   // that's how you sort a whole structure 
  
    

          int s=0;

      for(i=0;i<n;i++) 
      {
          s+=vec[i].t*vec[i].s;
       //  cout<<vec[i].d<<" "<<vec[i].t<<" "<<vec[i].s<<endl;
      } 
     
    cout<<s<<endl;
        

}

int main ()                                                             
{
    int t=1;
    cin>>t;
    while(t--)
    {
        prgm();
    }
    return 0;              
}                                                         
