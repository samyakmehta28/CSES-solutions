#include <bits/stdc++.h>
using namespace std;


 
int main() {
    int n;
    cin>>n;
    vector<int>nums;
    int sum=0;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
        sum=sum+num;
    }
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j>=nums[i-1]){
                dp[i][j]=dp[i-1][j-nums[i-1]] ;
            }
            dp[i][j]=dp[i][j] || dp[i-1][j];
        }
    }
    vector<int>res;
    for(int j=1;j<=sum;j++){
        if(dp[n][j]){
            res.push_back(j);
        }
    }
    cout<<res.size()<<endl;
    for(auto ans: res){
        cout<<ans<<' ';
    }
	return 0;
}

