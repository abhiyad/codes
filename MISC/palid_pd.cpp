#include <bits/stdc++.h>
using namespace :: std;
int main ()
{
    int n,i,j,l;
    string str;
    cin>>str;
    n=str.length();
    bool dp[n][n]={0};
    for(i=0;i<n;i++)dp[i][i]=true;
    for(l=2;l<n;l++)
    {
        for(i=0;i<n-l+1;i++)
        {
            j=i+l-1;
            if(l==2)
            dp[i][j]=(str[i]==str[j]);
            else
                dp[i][j]=(str[i]==str[j])&&(dp[i+1][j-1]) ;
        }
    }
    for(i=0;i<n;i++)
    {  
        for(j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl; 
    }

    int c[n];
    cout << endl<<"***********************"<<endl;
    for(i=0;i<n;i++)
    {
        if(dp[0][i] == true)
            c[i]=0;
        else
        {
            c[i]=999999;
            for(j=0;j<i;j++)
                if(dp[j+1][i] == true && 1+c[j]<c[i])
                    c[i]=1+c[j];
        }
         for(int m=0;m<n;m++)cout<<c[m]<<" "; 
         cout<<endl;
         getchar();
    }
  

    return 0;
}





