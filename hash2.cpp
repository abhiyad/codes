#include <bits/stdc++.h>
#include <unordered_map>
#include <boost/functional/hash.hpp>
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
#define hash(a,b) unordered_map< a , b >
#define mk(a,b) make_pair(a,b)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define tr(v,it) for(typeof((v).begin()) it = (v).begin(); it != (v).end() ; it++)
#define vpresent(v,x) ((v).find(x) != (v).end())
#define present(v,x) (find(all(v),x) != (v).end())  
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;    
#define inf 2000000000
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        size_t seed=0;
        boost::hash_combine(seed,h1);
        boost::hash_combine(seed,h2);
        return h1 ^ h2;  
    }
};

int main ()
{
	pii slope;
    unordered_map<pair<int, int>, int , pair_hash> slope_hash;
    int n;cin>>n;int m=0;int mx=0;
	pii arr[n];
	fr(i,n){cin>>arr[i].first;cin>>arr[i].second;}
	fr(i,n)
	{
		m=0;
		int overlap=0;
		int vertical=0;
		frr(j,i+1,n)
		{
			if(arr[i]==arr[j])overlap++;
			else if(arr[j].first==arr[i].first)vertical++;
			else
			{	
				int dy=arr[j].second-arr[i].second;
				int dx=arr[j].first-arr[i].first;
				int g=__gcd(dy,dx);
				dx/=g;
				dy/=g;
				slope_hash[mk(dx,dy)]++;
				m=max(m,slope_hash[mk(dx,dy)]);
			}
			m=max(m, vertical);
		}
		mx=max(mx,m+1+overlap);
		slope_hash.clear();
	}
	cout<<mx<<endl;
	return 0;
}