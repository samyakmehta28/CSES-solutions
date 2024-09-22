#include <bits/stdc++.h>
using namespace std;

int mod = pow(10,9)+7;
 
int main() {
    int n,target;
    cin>>n>>target;
    vector<int>coins;
    for(int i=0;i<n;i++){
        int coin;
        cin>>coin;
        coins.push_back(coin);
    }
    vector<int>dp(target+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=target;i++){
        for(int j=0;j<coins.size();j++){
            if(i>=coins[j] && dp[i-coins[j]]!=INT_MAX){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    if(dp[target]==INT_MAX){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<dp[target]<<endl;
	return 0;
}