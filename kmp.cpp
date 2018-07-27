#include <bits/stdc++.h>
using namespace std;  
#define ll long long int
#define ull unsigned long long int
#define uint unsigned int     
#define read(n) scanf("%d",&n)
#define readll(n) scanf("%lld",&n)
#define read2(n,m) scanf("%d%d",&n,&m)
#define read3(n,m,l) scanf("%d%d%d",&n,&m,&l)     
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,a,b)   for(int i=a;i<b;i++)
#define rf(i,n)     for(int i=n-1;i>=0;i--)     
#define init(mem,v) memset(mem,v,sizeof(mem))  
#define sz(v) ((v).size())
#define vc(r) vector< r >
#define mk(a,b) make_pair(a,b)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define tr(v,it) for(typeof((v).begin()) it = (v).begin(); it != (v).end() ; it++)
#define vpresent(v,x) ((v).find(x) != (v).end())
#define present(v,x) (find(all(v),x) != (v).end())  
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;    
#define inf 2000000000


int main ()
{
	string txt,pat;
	cin>>pat;
	int n=pat.length();
	int lps[n]={0};
	int len=0,i=1;
	while(i<n)
	{
		if(pat[i]==pat[len])
			{
				len++;
				lps[i]=len;
				i++;
			}
		else
			{
				if (len==0)
					{
						lps[i]=0;
						i++;
					}
				else
						len=lps[len-1];
			}
	}
	cin>>txt;
	int m=txt.length();
	int j=0;i=0;
	while(i<m)
	{
		//cout<<i<<" "<<j<<endl;
		if(pat[j]==txt[i])
		{
			i++;j++;
		}
		if(j==n)
		{
			cout<<"found at "<<i;
			j=lps[m-1];
		}
		if(pat[j]!=txt[i])
		{
			if(j!=0)j=lps[j-1];
			else
				i++;
		}
	}
	return 0;
}