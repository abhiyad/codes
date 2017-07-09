#include <iostream>
#include <list>
#include <vector>
using namespace :: std;
struct node
{
    int val;
    vector <int> adj; // list of all adjacent nodes ie. their val number
};
vector <node> nd; // vector for all nodes in graph 

void addside(int a,int b)
{
    nd[a].val=a;
    nd[a].adj.push_back(b);// for undirected do
   // nd[b].adj.push_back(a);
}

void dfs(int a,bool visited[])
{
    visited[a]=true;
    cout<<nd[a].val<<" -> ";
    vector <int> :: iterator j;
    for(j=nd[a].adj.begin();j!=nd[a].adj.end();j++)
    {
        if(!visited[*j])
        {
            dfs(*j,visited);
        }
    }
}


void driverdfs(int n)
{
    int i;
    bool visited[n];
    for(i=1;i<n+1;i++)
    {   nd[i].val=i;
        visited[i]=false;
    
    }
    for(i=1;i<n+1;i++)
    {
        if(!visited[i])
            dfs(i,visited);
    }
}


int main ()
{
   int n,q;
   cin>>n; // total no of vertices
   nd.resize(n+1);
   cin>>q;// no of edges 
   int i;
    for(i=0;i<q;i++)
   {
       int a,b;
       cin>>a>>b;
       addside(a,b);
   }
  
   for(i=0;i<n;i++)
   {
       if(nd[i].val==0)continue;
       cout<<"Vertex :"<<nd[i].val<<" adjacented by : ";
       vector <int>::iterator j;
       for(j=nd[i].adj.begin();j!=nd[i].adj.end();j++)
           cout<<" "<<*j;
       cout<<endl;
   }
   driverdfs(n);
   return 0;
}

