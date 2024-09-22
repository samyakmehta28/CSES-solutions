#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n,sum;
	cin>>n>>sum;
	vector<int>costs;
	vector<int>pages;
	for(int i=0;i<n;i++){
	    int cost;
	    cin>>cost;
	    costs.push_back(cost);
	}
	for(int i=0;i<n;i++){
	    int page;
	    cin>>page;
	    pages.push_back(page);
	}
	int mod = pow(10,9)+7;
	vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=sum;j++){
	        if(j>=costs[i-1]){
	            dp[i][j]=dp[i-1][j-costs[i-1]] + pages[i-1];
	        }
	        dp[i][j]=max(dp[i][j],dp[i-1][j]);
	    }
	}
	cout<<dp[n][sum]<<endl;
	return 0;
}
