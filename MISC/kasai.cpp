#include<bits/stdc++.h>
using namespace :: std;
#define ll int
ll lcp[1000];
void kasai(string s, int sa[])
{
    ll n=s.size(),k=0;
    ll rank[n];
    for(ll i=0; i<n; i++) rank[sa[i]]=i;

    for(ll i=0; i<n; i++, k?k--:0)
    {
        if(rank[i]==n-1) {k=0; continue;}
        ll j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
    }
}
int main ()
{
    ll sa[]={5,3,1,0,4,2};
    string s = "banana";
    kasai(s,sa);
    for(ll i=0;i<6;i++)
        cout<<lcp[i]<<" "<<endl;
    return 0;
}
