#include <bits/stdc++.h>
using namespace std;


 
int main() {
    int n;
    cin>>n;
    vector<int>nums;
    int sum=0;
    for(int i=1;i<=n;i++){
        nums.push_back(i);
        sum=sum+i;
    }
    if(sum%2){
        cout<<"0"<<endl;
        return 0;
    }
    int target=sum/2;
    int mod = pow(10,9)+7;
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(j>=nums[i-1]){
                dp[i][j]=dp[i-1][j-nums[i-1]];
            }
            dp[i][j]=(dp[i][j] + dp[i-1][j])%mod;
        }
    }
    cout<<dp[n][target]<<endl;
    
	return 0;
}

