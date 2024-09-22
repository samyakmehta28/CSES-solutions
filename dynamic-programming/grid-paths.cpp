#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	vector<string>grid;
	for(int i=0;i<n;i++){
	    string row;
	    cin>>row;
	    grid.push_back(row);
	}
	int mod = pow(10,9)+7;
	vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
	        if(i==1 && j==1 && grid[i-1][j-1]=='.'){
	            dp[i][j]=1;
	            continue;
	        }
	        if(grid[i-1][j-1]=='.'){
	            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
	        }
	        
	    }
	}
	cout<<dp[n][n]<<endl;
	return 0;
}
