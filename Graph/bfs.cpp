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
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;    
#define inf 2000000000

//------------------------------------------------

struct node 
{
    int val;
    vector <int> adj;
    int dis;
};
struct node nd[100];
void edge(int u,int v)
{
    nd[u].val=u;
    nd[v].val=v;
    nd[u].adj.push_back(v);
    nd[v].adj.push_back(u);
}
void display()
{
    int i;
    fr(i,10)
    {
        cout<<nd[i].val<<" ----- ";
        fr(j,nd[i].adj.size())
        {
            cout<<nd[i].adj[j]<<" ";
        }
        cout<<endl;
    }
}
void bfs()
{
    int visited[100]={0};
    list <int> q;
    visited[0]=1;
    q.push_back(0);
    while(!q.empty())
    {
        int t=q.front();
        cout<<t<<" - ";
        q.pop_front();
        fr(i,nd[t].adj.size())
        {
            if(!visited[i])
            {
                visited[i]=1;
                q.push_back(i);
            }
        }
    }
}

int main ()
{
    edge(0,1);
    edge(0,2);
    edge(0,3);
    edge(1,2);
    edge(2,4);
    edge(2,5);
    edge(4,5);
    edge(3,5);
    edge(3,6);
    edge(4,7);
    edge(6,7);
  
  
    display();
    bfs();
    return 0;
}





        



