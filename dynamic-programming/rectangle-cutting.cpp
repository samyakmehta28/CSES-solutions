#include <bits/stdc++.h>
using namespace std;

int solve(int n,int m,vector<vector<int>>&dp){
    if(n==m){
        return 0;
    }
    if(dp[n][m]!=INT_MAX){
        return dp[n][m];
    }
    int ans=INT_MAX;
    for(int i=1;i<=m/2;i++){
        ans=min(ans,solve(n,m-i,dp)+solve(n,i,dp)+1);
    }
    for(int i=1;i<=n/2;i++){
        ans=min(ans,solve(n-i,m,dp)+solve(i,m,dp)+1);
    }
    return dp[n][m]=ans;
    
}

 
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
    cout<<solve(n,m,dp)<<endl;
    
    // cout<<dp[n][m]<<endl;
	return 0;
}

