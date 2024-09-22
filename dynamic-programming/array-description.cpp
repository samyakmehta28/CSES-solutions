#include <bits/stdc++.h>
using namespace std;


 
int main() {
    int n,m;
    cin>>n>>m;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    int mod = pow(10,9)+7;
    vector<vector<int>>dp(n,vector<int>(m+1,0));
    if(nums[0]==0){
         for(int i=1;i<=m;i++){
            dp[0][i]=1;
        }
    }
    else{
        dp[0][nums[0]]=1;
    }
    for(int i=1;i<n;i++){
        if(nums[i]!=0){
            dp[i][nums[i]]=dp[i-1][nums[i]];
            if(nums[i]>0){
                dp[i][nums[i]]+=dp[i-1][nums[i]-1];
                dp[i][nums[i]]%=mod;
            }
            if(nums[i]<m){
                dp[i][nums[i]]+=dp[i-1][nums[i]+1];
                dp[i][nums[i]]%=mod;
            }
            continue;
        }
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>0){
                dp[i][j]+=dp[i-1][j-1];
                dp[i][j]%=mod;
            }
            if(j<m){
                dp[i][j]+=dp[i-1][j+1];
                dp[i][j]%=mod;
            }
        }
    }
    int sum=0;
    for(int j=0;j<=m;j++){
        sum=sum+dp[n-1][j];
        sum%=mod;
    }
    cout<<sum<<endl;
	return 0;
}

