#include <bits/stdc++.h>
using namespace :: std;
struct suffix
{
    int i;
    int rank[2];
};

int cmp(struct suffix a, struct  suffix b)
{
    if(a.rank[0]!=b.rank[0])
        return (a.rank[0]<b.rank[0]);
    else
        return (a.rank[1]<b.rank[1]);
}


int main ()
{
    int i,j,k,l;
    string str;
    cin>>str;
    l=str.length();
    suffix arr[100];
    for(i=0;i<l;i++)
    {
        arr[i].i=i;
        arr[i].rank[0]=str[i]-'a';
        arr[i].rank[1]=-1;
        if(i+1!=l)
        arr[i].rank[1]=str[i+1]-'a';
    }
    sort(arr,arr+l,cmp);
    
    // sorting done according to first two letters , now proceed to first four
    for(k=4;k<2*l;k*=2){
    int rank0=arr[0].rank[0];
    int rank1=arr[0].rank[1];
    int c=0;
    int ind[l];
    ind[arr[0].i]=0;
    for(i=1;i<l;i++)
    {
        if(arr[i].rank[0]==rank0 && arr[i].rank[1]==rank1)
            arr[i].rank[0]=c;
        else
        {
            rank0=arr[i].rank[0];
            rank1=arr[i].rank[1];
            arr[i].rank[0]=++c;
        }
        ind[arr[i].i]=i;
    }
    // you got the rank[0] for k = 4 , now get rank[1] of suffix[i+k/2] for each i if i+k/2 < n else put a '-1' there
    
    for(i=0;i<l;i++)
    {
        int nexti = arr[i].i + k/2;
        if(nexti<l)
            arr[i].rank[1]=arr[ind[nexti]].rank[0];
        else
            arr[i].rank[1]=-1;
    }
    
    sort(arr,arr+l,cmp);
    }
    for(i=0;i<l;i++)
        cout<<arr[i].rank[0]<<" "<<arr[i].rank[1]<<" "<<arr[i].i<<endl;
    return 0;
}

        





