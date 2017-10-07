#include <iostream>
#include <list>
#include <vector>
using namespace :: std;
struct node
{
    int val;
    int num;
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
    cout<<nd[a].val<<"("<<nd[a].num<<")"<<" -> ";
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
    { 
        visited[i]=false;
    
    }
    for(i=1;i<n+1;i++)
    {
        if(!visited[i])
            dfs(i,visited);
    }
}
//========================================================================
int n;
int i=0,j=0;
int chains[100][100];
int chainsize[100]={0};
void hld(int cur)
{   
    chains[i][j++]=cur;
    chainsize[i]++;
    int sci=-1;
    int max=-1;
    vector <int> :: iterator k;
    for(k=nd[cur].adj.begin();k!=nd[cur].adj.end();k++)
    {
        if(nd[*k].num>max)
        {
            max=nd[*k].num;
            sci=*k;
        }
    }
    if(sci>=0)hld(sci);
    for(k=nd[cur].adj.begin();k!=nd[cur].adj.end();k++)
    {
        if(*k!=sci)
        {
            i++;
            j=0;
            hld(*k);
        }
    }
}
//=========================================================================
void display()
{
    int k,j;
    for(k=0;k<i+1;k++)
    { 
        for(j=0;j<chainsize[k];j++)
        {
            cout<<chains[k][j]<<" ";
        }
        cout<<endl;
    }
}


int main ()
{
   int q;
   cin>>n; // total no of vertices
   nd.resize(n+1);
   cin>>q;// no of edges 
   int i;
   // lets assume that each vertex has value same as its vertex number

    for(i=0;i<q;i++)
   {
       int a,b;
       cin>>a>>b;
       addside(a,b); // that's how to add and edge
   }
    for(i=1;i<n+1;i++)nd[i].num=nd[i].adj.size();  
   // down there is just shit
   for(i=0;i<n;i++)
   {   nd[i+1].val=i+1;
       if(nd[i].val==0)continue;
       cout<<"Vertex :"<<nd[i].val<<" adjacented by : ";
       vector <int>::iterator j;
       for(j=nd[i].adj.begin();j!=nd[i].adj.end();j++)
           cout<<" "<<*j;
       cout<<endl;
   }
   driverdfs(n);    // that's to go for DFS
   cout<<endl;
   hld(1);
   display();
   return 0;
}

