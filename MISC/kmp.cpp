#include <bits/stdc++.h>
using namespace :: std;
int lps[2000005];
void compute(string a)
{
    int i,k=0,q;
    lps[1]=0;
    for(q=2;q<=a.length();q++)
    { 
        while(k>0 && a[k]!=a[q-1])k=lps[k];
        if(a[k]==a[q-1])++k;
        lps[q]=k;
    } 
}
    
void kmp(string a ,string b)
{
    int i=0,j=0;
    int best=0,ans=0;
    for(i=0;i<b.length();i++)
    {
        while(j>0 && a[j]!=b[i])
            j=lps[j];
        if(a[j]==b[i])j++;
        if(j>best)
        {
            best=j;
            ans=i-j+1;
        }
    }
    cout<<ans;
}

int main ()
{
    int n;
    cin>>n;
    string a;
    char b[2000005];
    cin>>a>>b;
    compute(a);
    for(int i=0;i<a.length();i++)
        b[i+a.length()]=b[i];
    b[2*a.length()]='\0';
    kmp(a,b);
    return 0;
}


