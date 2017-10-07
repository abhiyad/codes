#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
#define ll  int
#define MAXN 65536
#define MAXLG 17

struct entry
{
    ll nr[2];
    ll p;
} L[MAXN];

int cmp(struct entry a, struct entry b)
{
    return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}
ll arr[MAXN];
void suffix(string A)
{
    ll P[MAXLG][MAXN];
    ll N,i;
    ll stp, cnt;
    for(N=A.length(), i = 0; i < N; i++)
        P[0][i] = A[i] - 'a';

    for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
    {
        for(i=0; i < N; i++)
        {
            L[i].nr[0]=P[stp- 1][i];
            L[i].nr[1]=i +cnt <N? P[stp -1][i+ cnt]:-1;
            L[i].p= i;
        }
        sort(L, L+N, cmp);
        for(i=0; i < N; i++)
            P[stp][L[i].p] =i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[stp][L[i-1].p] : i;
    }
     for(i=0;i<N;i++)
         arr[i]=L[i].p;
}
int main ()
{
    string str;
    cin>>str;
    suffix(str);
    // NOW arr[] will have the suffix array for the given string 
    for(ll i=0;i<str.length();i++)
        cout<<arr[i]<<endl;
    return 0;
}
