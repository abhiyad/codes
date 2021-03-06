    #ifdef ONLINE_JUDGE
    #include <bits/stdc++.h>
    #else
    #include </Users/gouravr/scratchpad/stdc++.h>
    #endif
     
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
     
    #define DB(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
    #define DB2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
    #define DB3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;
    #define DB4(a, b, c, d)    cout<<__LINE__<<" :: "<<#a<< ": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
     
    typedef pair<int,int> pii;
    typedef pair<pii,pii> ppi;
     
    #define inf 2000000000
    const int mx=1005;
    char mp[mx][mx];
    bool vis[mx][mx];
     
    int dp[mx][mx][4];
    int n,m;
     
    // largest rectangle that encloses these two points
    ppi largest(ppi a,ppi b){
        a.first.first=min(a.first.first,b.first.first);
        a.first.second=min(a.first.second,b.first.second);
        a.second.first=max(a.second.first,b.second.first);
        a.second.second=max(a.second.second,b.second.second);
        return a;
    }
     
    // top-left, bottom-right
    ppi flood_fill(int i,int j){
        if(i < 0 or j < 0 or i >= n or j >= m or mp[i][j] == 'B' or vis[i][j]) return ppi(pii(inf,inf),pii(-inf,-inf));
        vis[i][j]=true;
        ppi ret=ppi(pii(i - 1,j - 1),pii(i + 1,j + 1));
        ret=largest(ret,flood_fill(i+1,j));
        ret=largest(ret,flood_fill(i-1,j));
        ret=largest(ret,flood_fill(i,j+1));
        ret=largest(ret,flood_fill(i,j-1));
     
        return ret;
    }
     
    #define get_dp(i,j,k) ((i>=0 and j>=0 and i<n and j<m)?dp[i][j][k]:0)
    int main(){
        int t;
        read(t);
        while(t--){
            read2(n,m);
            fr(i,n) scanf("%s",mp[i]);
            init(vis,0);
            init(dp,0);
     
            fr(i,n) fr(j,m){
                if(mp[i][j]=='W' and !vis[i][j]){
                    ppi p=flood_fill(i,j);
                    int x1=p.first.first;
                    int y1=p.first.second;
                    int x2=p.second.first;
                    int y2=p.second.second;
     
                    if(x1<0 or y1<0 or x2>n-1 or y2>m-1) continue;
                    dp[x2][y2][0]++;
                    dp[x2][y1][1]++;
                    dp[x1][y2][2]++;
                    dp[x1][y1][3]++;
                }
            }
     
            // cumulative sums
            for(int i=0;i<n;i++) for(int j=0;j<m;j++){
                dp[i][j][0]+=get_dp(i-1,j,0)+get_dp(i,j-1,0)-get_dp(i-1,j-1,0);
            }
            for(int i=0;i<n;i++) for(int j=m-1;j>=0;j--){
                dp[i][j][1]+=get_dp(i-1,j,1)+get_dp(i,j+1,1)-get_dp(i-1,j+1,1);
            }
            for(int i=n-1;i>=0;i--) for(int j=0;j<m;j++){
                dp[i][j][2]+=get_dp(i+1,j,2)+get_dp(i,j-1,2)-get_dp(i+1,j-1,2);
            }
            for(int i=n-1;i>=0;i--) for(int j=m-1;j>=0;j--){
                dp[i][j][3]+=get_dp(i+1,j,3)+get_dp(i,j+1,3)-get_dp(i+1,j+1,3);
            }
     
            bool poss=false;
            fr(i,n) fr(j,m){
                bool ok=true;
                if(i>0   and j>0   and dp[i-1][j-1][0]>0) ok=false;
                if(i>0   and j<m-1 and dp[i-1][j+1][1]>0) ok=false;
                if(i<n-1 and j>0   and dp[i+1][j-1][2]>0) ok=false;
                if(i<n-1 and j<m-1 and dp[i+1][j+1][3]>0) ok=false;
                
                if(ok) {
                    poss=true;
                }
            }
            if(poss) printf("YES\n");
            else printf("NO\n");
        }
    } 
