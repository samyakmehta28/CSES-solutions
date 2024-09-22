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
	for(int i=0;i<coins.size();i++){
	    for(int j=1;j<=target;j++){
	        if(j>=coins[i]){
	            dp[j]=(dp[j]+dp[j-coins[i]])%mod;
	        }
	    }
	}
	cout<<dp[target]<<endl;
	return 0;
}
