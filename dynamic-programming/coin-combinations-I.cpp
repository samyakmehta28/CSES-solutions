#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n,target;
	cin>>n>>target;
	vector<int>coins;
	for(int i=0;i<n;i++){
	    int coin;
	    cin>>coin;
	    coins.push_back(coin);
	}
	int mod = pow(10,9)+7;
	vector<int>dp(target+1,0);
	dp[0]=1;
	for(int i=1;i<=target;i++){
	    for(int j=0;j<coins.size();j++){
	        if(i>=coins[j]){
	            dp[i]=(dp[i]+dp[i-coins[j]])%mod;
	        }
	    }
	}
	cout<<dp[target]<<endl;
	return 0;
}
