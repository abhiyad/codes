#include <bits/stdc++.h>
using namespace :: std;
#define ll long long int 
#define pi pair<ll,ll>
ll sgmt[1000]={0};
ll lazy[1000]={0};
void build(ll arr[],ll i,ll lo,ll hi)
{
    if(lo==hi)
        sgmt[i]=arr[lo];
    else 
    {
        ll mid = lo + (hi-lo)/2;
        build(arr,2*i+1,lo,mid);
        build(arr,2*i+2,mid+1,hi);
        sgmt[i]=sgmt[2*i+1]+sgmt[2*i+2];
    }
}
void update(ll l,ll r,ll k,ll lo,ll hi,ll i)
{
    if(r<lo || l>hi)return ;
    if(lazy[i]!=0)sgmt[i]+=(hi-lo+1)*lazy[i];
    if(l<=lo && r>=hi)
    {
        sgmt[i]+=(hi-lo+1)*k;
        ll mid = lo + (hi-lo)/2;
        lazy[2*i+1]=k;
        lazy[2*i+2]=k;
    }
    else
    {
        ll mid = lo + (hi-lo)/2;
        update(l,r,k,lo,mid,2*i+1);
        update(l,r,k,mid+1,hi,2*i+2);
        sgmt[i]=sgmt[2*i+1]+sgmt[2*i+2];
    }
}
ll get(ll l,ll r,ll lo,ll hi,ll i)
{
    if(r<lo || l>hi)return 0;
    if(lazy[i]!=0)
    {
        sgmt[i]+=(hi-lo+1)*lazy[i];
        lazy[2*i+1]+=lazy[i];
        lazy[2*i+2]+=lazy[i];
    }
    if(l==lo && r==hi)return sgmt[i];
    else
    {
        ll mid = lo + (hi-lo)/2;
        sgmt[2*i+1]=get(l,r,lo,mid,2*i+1);
        sgmt[2*i+2]=get(l,r,mid+1,hi,2*i+2);
        sgmt[i]=sgmt[2*i+1]+sgmt[2*i+2];
        return sgmt[i];
    }
}

    
int main()
{
    ll arr[]={1,2,3,4,5,6,7,8}; 
    build(arr,0,0,7); 
    update(0,3,1000,0,7,0);
    cout<<lazy[3]<<endl;
    cout<<get(1,1,0,7,0);
    return 0;
}
        



