#include <bits/stdc++.h>
using namespace :: std;
typedef long long int ll;
long long int st[100000]={0};


void add(ll i,ll k,ll lo, ll hi,ll c)
{
    if(lo==hi && lo==i)
    {
        st[c]+=k;
        return;
    }
    if(i>=lo && i<=hi)
    { 
        st[c]+=k;
        ll mid = lo + (hi-lo)/2;
        add(i,k,lo,mid,2*c+1);
        add(i,k,mid+1,hi,2*c+2);
    }
}


ll constructST(ll arr[],ll lo,ll hi,ll i)
{
    if(lo==hi)
    {
        st[i]=arr[lo];
        return st[i];
    }
    else
    {
        ll mid = lo +(hi-lo)/2;
        ll j = constructST(arr,lo,mid,2*i+1);
        ll k = constructST(arr,mid+1,hi,2*i+2);
        st[i]=j+k;
        return st[i];
    }
}

int main ()
{
    ll n,i,j;
    ll r=1;
    cin>>n;
    while(r<n)r*=2;
    ll arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    constructST(arr,0,n-1,0);
    cout<<endl;
    for(i=0;i<2*n-1;i++)
        cout<<st[i]<<" ";
    add(2,100,0,n-1,0);
    cout<<endl;
    for(i=0;i<2*n-1;i++)
        cout<<st[i]<<" ";  

    return 0;
}

