#include <bits/stdc++.h>
using namespace :: std;
typedef long long int ll;
long long int st[100000]={0};
   
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

    return 0;
}

