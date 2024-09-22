#include <bits/stdc++.h>
using namespace std;


 
int main() {
    string a,b;
    cin>>a>>b;
    int n = a.size();
    int m = b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=i;
    }
    for(int j=1;j<=m;j++){
        dp[0][j]=j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            
            dp[i][j]=min(dp[i][j],min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1);
            
            
        }
    }
    cout<<dp[n][m]<<endl;
	return 0;
}

