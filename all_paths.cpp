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


struct graph
{
	vc(int)adj;
};
vc(struct graph)node;

void dfs(int s,int d,int* visited)
{
	cout<<s<<endl;
	if(s==d)cout<<" yes "<<endl;
	else
	{
		visited[s]=1;
		tr(node[s].adj,it)
		{
			if(!visited[*it])
				dfs(*it,4,visited);
		}
	}
	visited[s]=0;
}


int main ()
{
	int m,n;
	cin>>m>>n;
	node.resize(m);
	fr(i,n)
	{
		int u,v;
		cin>>u>>v;
		node[u].adj.pb(v);
	}
	int visited[m]={0};
	dfs(1,4,visited);
	return 0;
}