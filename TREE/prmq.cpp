    #include <bits/stdc++.h>
    using namespace std;
     
    vector<int>seg[1000005];
    vector <int> v[100005];
     
    void build(int low,int high,int node)
    {
        if(low>high)
            return;
        if(low == high)
        {
            seg[node]=v[low];
            return;
        }
        int mid=low+high>>1;   // note this 
        build(low,mid,2*node+1);
        build(mid+1,high,2*node+2);
        merge(seg[2*node+1].begin(),seg[2*node+1].end(),seg[2*node+2].begin(),seg[2*node+2].end(),back_inserter(seg[node])); // and this 
    }
     
    int query(int low,int high,int lq,int hq,int x,int y,int node)
    {
        if(low>hq || high<lq)
            return 0;
        if(lq<=low && high<=hq)
        {
            int left,right;
            if(x<y) {
                left=lower_bound(seg[node].begin(),seg[node].end(),x)-seg[node].begin();
                right=upper_bound(seg[node].begin(),seg[node].end(),y)-seg[node].begin();
                return right-left;
            }
            else {
                left=upper_bound(seg[node].begin(),seg[node].end(),x)-seg[node].begin();
                right=lower_bound(seg[node].begin(),seg[node].end(),y)-seg[node].begin();
                return left-right;
            }
        }
        int mid=low+high>>1;         // this as well 
        return query(low,mid,lq,hq,x,y,2*node+1)+query(mid+1,high,lq,hq,x,y,2*node+2);
    }
     
    int main()
    {
     
        int n,q;
        scanf("%d",&n);
        int temp;
        register int i;
        for(i=0; i<n; i++)   {
            scanf("%d",&temp);
            while(temp%2 == 0)
            {
                v[i].push_back(2);
                temp/=2;
            }
            int j;
            for(j=3; j*j<=temp; j+=2) {
                while(temp%j==0)        {
                    v[i].push_back(j);
                    temp/=j;
                }
            }
            if(temp>2)
                v[i].push_back(temp);
        }


    

        build(0,n-1,0);
        scanf("%d",&q);
        int x,y,l,r;
        for(i=0; i<q; i++)
        {
            scanf("%d %d %d %d",&l,&r,&x,&y);
            printf("%d\n",query(0,n-1,l-1,r-1,x,y,0));
        }
        return 0;
    } 
