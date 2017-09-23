#include <stdio.h>
#include<vector>
 
using namespace std;
vector<int> v[100001];
int l[100001],r[100001],k[100001],a[100001],prev[100001],next[100001],count[100001],ans[100001];
int t,n,m,i,j;
int main() 
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<=100000;i++)
        {
            v[i].clear();
            count[i]=0;
            ans[i]=0;
            prev[i]=i;
            next[i]=i;
        }
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&l[i],&r[i],&k[i]);
        }
        for(i=2;i<=n;i++)
        {
            if(a[i]==a[i-1])prev[i]=prev[i-1];
        }
        
        for(i=n-1;i>=1;i--)
        {
            if(a[i]==a[i+1])next[i]=next[i+1];
        }
        
        for(i=0;i<m;i++)
        {
            l[i]--;
            v[l[i]].push_back(i);
            v[r[i]].push_back(i);
        }
        int c=1;
        a[0]=-2376;
        for(i=1;i<=n;i++)
        {
            if(a[i]==a[i-1])c++;
            else c=1;
            count[c]++;
            for(j=0;j<v[i].size();j++)
            {
                int p=v[i][j];
                if(next[l[p]]>=r[p])ans[p]=1;
                else
                {
                    if(r[p]==i)ans[p]+=count[k[p]];
                    else
                    {
                        ans[p]-=count[k[p]];
                        if(a[l[p]]==a[l[p]+1])
                        {
                //            return 1;
                            if(next[l[p]]-prev[l[p]]+1>=k[p])
                            {
                                if(l[p]-prev[l[p]]+1>=k[p])
                                {
                                    if(next[l[p]]-l[p]>=k[p])
                                        ans[p]++;
                                }
                                else if(next[l[p]]-l[p]<k[p])ans[p]--;
                            }
                        }
                    }
                }
            }
        }
        for(i=0;i<m;i++)printf("%d\n",ans[i]);
    }
	return 0;
}
