#include <bits/stdc++.h>
using namespace std;  
#define ll long long long long
#define ull unsigned long long long long
#define ulong long unsigned long long     
#define read(n) scanf("%d",&n)
#define readll(n) scanf("%lld",&n)
#define read2(n,m) scanf("%d%d",&n,&m)
#define read3(n,m,l) scanf("%d%d%d",&n,&m,&l)     
#define fr(i,n)     for(long long i=0;i<n;i++)
#define frr(i,a,b)   for(long long i=a;i<b;i++)
#define rf(i,n)     for(long long i=n-1;i>=0;i--)     
#define init(mem,v) memset(mem,v,sizeof(mem))    
typedef pair<long long,long long> pii;
typedef pair<pii,pii> ppi;    
#define inf 2000000000
//==================================================
long long prefix[100001][1001];// used to calculate distance (diameter weight)
long long diameter[100001]={0};// has the diameter of each graph
long long a[100001]={0};// no of vertices in each cycle
long long u[100000]={0},v[100000]={0},w[100000]={0};
long long dist[100001],dist2[100001];// distance of each cycle from first cycle
long long total_distance=0;
int main ()
{
    long long t;
    cin>>t;
    while(t--){
    
    long long n,q;
    cin>>n>>q;
    fr(i,n)
    {
        cin>>a[i]; 
        prefix[i][1]=0;
        for(long long j=1;j<=a[i];j++)
        {
            long long t;cin>>t;
            prefix[i][j]=prefix[i][j-1]+t;
        }
    }
    fr(i,n){cin>>u[i]>>v[i]>>w[i];total_distance+=w[i];}
    long long d1=abs(prefix[0][u[0]-1]-prefix[0][v[n-1]-1]);
    long long d2=prefix[0][a[0]]-d1;
    diameter[0]=min(d1,d2);

    //cout<<"here :"<<diameter[0]<<endl;

    total_distance+=diameter[0];
    for(long long i=1;i<n;i++)
    {
        d1=abs(prefix[i][u[i]-1]-prefix[i][v[i-1]-1]);
        d2=prefix[i][a[i]]-d1;
        diameter[i]=min(d1,d2);
        total_distance+=diameter[i];
    }
    // all diameters have been evaluated 
    // all prefix sum have been evaluated 
    // now distance from each graph

    //cout<<total_distance<<endl;

    dist[0]=w[0];
    for(long long i=1;i<n;i++)
    {
        dist[i]=dist[i-1]+w[i]+diameter[i];
    }
    
    //================================================ now queries
    // assume c2 is larger

    while(q--){
    
    long long v1,c1,v2,c2;
    long long x1,x2,y1,y2; // x1 ,y1 for graph c1 and x2 , y2 for graph c2
    cin>>v1>>c1>>v2>>c2;
    if(c1>c2){ 
        long long c=c1;
        c1=c2;
        c2=c;
        c=v1;
        v1=v2;
        v2=c;
    }
    x1=u[c1-1];x2=v[c2-2];
    if(c1!=1){y1=v[c1-2];y2=u[c2-1];}
    if(c1==1){y1=v[n-1];y2=u[c2-1];}

    //cout<<x1<<" "<<x2<<endl; // either path is v1 to x1 to x2 to v2 (main path)
    //cout<<y1<<" "<<y2<<endl; // or path is v1 to y1 to y2 to v2 ( opposite path)
   // fr(i,n)cout<<dist[i]<<" "<<dist2[i]<<endl;
    long long path1=0,path2=0;;
    if(c1!=1);
    path1=dist[c2-2]-dist[c1-2]-diameter[c1-1];
    if(c1==1)
    path1=dist[c2-2];
    path2=total_distance - path1 - diameter[c1-1] - diameter[c2-1];
    // correct path1 and path2

    d1=abs(prefix[c1-1][v1-1]-prefix[c1-1][x1-1]);
    d2=prefix[c1-1][a[c1-1]]-d1;
    d1=min(d1,d2);
    
    long long e1=abs(prefix[c2-1][v2-1]-prefix[c2-1][x2-1]);
    long long e2=prefix[c2-1][a[c2-1]]-e1;
    e1=min(e1,e2);
    
    long long f1=abs(prefix[c1-1][v1-1]-prefix[c1-1][y1-1]);
    long long f2=prefix[c1-1][a[c1-1]]-f1;
    f1=min(f1,f2);
    
    long long g1=abs(prefix[c2-1][v2-1]-prefix[c2-1][y2-1]);
    long long g2=prefix[c2-1][a[c2-1]]-g1;
    g1=min(g1,g2);
    cout<<min(d1+e1+path1,f1+g1+path2)<<endl;
    }
    }
    return 0;
}

