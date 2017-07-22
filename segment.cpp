#include <iostream>
using namespace ::std;

int seg[11];
int arr[]={1,3,5,7,9,11};
 
int construct(int lo,int hi,int i)
{
    if(lo==hi)
    {
        seg[i]=arr[lo];
        return arr[lo];
    }
    else
    {
        seg[i]=construct(lo,(hi+lo)/2,2*i+1)+construct(1+(hi+lo)/2,hi,2*i+2);
        return seg[i];
    }
}
void update(int i,int diff,int lo,int hi,int t)
{
    if(t<lo || t>hi)return;           
        seg[i]+=diff;    
        if(lo!=hi){
        int mid=(hi+lo)/2;
        update(2*i+1,diff,lo,mid,t);
        update(2*i+2,diff,mid+1,hi,t);    }
    
}
int main ()
{
    int i;
    construct(0,5,0);
    for(i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
 
    for(i=0;i<11;i++)
    {
        cout<<seg[i]<<" ";
    }              
    cout<<endl;
    update(0,100,0,5,2);
   for(i=0;i<11;i++)
    {
        cout<<seg[i]<<" ";
    }              
    cout<<endl;
   
}


