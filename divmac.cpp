    #include<bits/stdc++.h>
     
    using namespace std;
     
    #define ll long long
    #define N 100005
    #define N1 1000005
     
    int a[ N ];
    int tree[ 4 * N ];
    int spf[ N1 ];
     
    void sieve(){	
    	for(int i = 2; i < N1; i++){
    		if(spf[i] == 0){
    			spf[i] = i;
    			for(int p = 2 * i; p < N1; p += i){
    				if(spf[p] == 0)
    					spf[p] = i;		
    			}
    		}
    	}
    }
     
    void build(int node, int start, int end)
    {
        if(start == end)
        {
        	   if(spf[a[start]]==0)
        		tree[node] = 1;
            else
        		tree[node]=spf[a[start]];
        }
        else
        {
            int mid = (start + end) / 2;
     
            build(2*node, start, mid);
     
            build(2*node+1, mid+1, end);
     
            tree[node] = max(tree[2*node], tree[2*node+1]);
        }
    }
     
    void updateRange(int node, int start, int end, int l, int r)
    {
        if (start > end or start > r or end < l)
            return;
     
        if(tree[node] == 1)
        	return;	
     
        if (start == end)
        {
            if(a[start] != 1)
            	a[start] = a[start] / spf[a[start]];
            if(a[start] == 1)
            	tree[node] = 1;
            else
            	tree[node] = spf[a[start]];
            return;
        }
     
        int mid = (start + end) / 2;
        updateRange(node*2, start, mid, l, r);
        updateRange(node*2 + 1, mid + 1, end, l, r);
     
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
     
    int query(int node, int start, int end, int l, int r)
    {
        if(r < start or end < l)
            return -1;
        
        if(tree[node]==1)
        	return 1;
        
        if(l <= start and end <= r)
            return tree[node];
            
        int mid = (start + end) / 2;
        int p1 = query(2*node, start, mid, l, r);
        int p2 = query(2*node+1, mid+1, end, l, r);
        return max(p1, p2);
    }
     
    int main(){
    	sieve();
        int test;
    	scanf("%d", &test);
    	while(test--){
    		int n, m;
    		scanf("%d %d", &n, &m);
    		for(int i = 1; i <= n; i++)
    			scanf("%d", &a[i]);
    		build(1, 1, n);
    		vector<int> ans;		
    		while(m--){
    			int type, l, r;
    			scanf("%d %d %d", &type, &l, &r);
    			if(!type){
    				updateRange(1, 1, n, l, r);
    			}
    			else{
    				ans.push_back(query(1, 1, n, l, r));
    			}
    		}
    		for(int i = 0; i < (int)ans.size(); i++)
    			printf("%d ", ans[i]);
    		printf("\n");
    	}
        
    	return 0;
    } 
