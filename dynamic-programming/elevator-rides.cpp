#include <bits/stdc++.h>
using namespace std;

int solve(int mask, vector<int>&weights, int maxWeight, vector<pair<int,int>>&dp){
    if(mask==0){
        dp[0]={1,0};
        return 1;
    }
    if(dp[mask].first!=-1){
        return dp[mask].first;
    }
    pair<int,int>res={INT_MAX,INT_MAX};
    for(int i=0;i<weights.size();i++){
        if(mask & (1<<i)){
            int min_rounds = solve((mask ^ (1<<i)),weights, maxWeight, dp);
            if(dp[(mask ^ (1<<i))].second+weights[i]<=maxWeight){
                res=min(res,{min_rounds,dp[(mask ^ (1<<i))].second+weights[i]});
            }
            else{
                res=min(res,{min_rounds+1,weights[i]});
            }
        }
    }
    dp[mask]=res;
    return res.first;
}
 
int main() {
    int n,maxWeight;
    cin>>n>>maxWeight;
    vector<int>weights;
    for(int i=0;i<n;i++){
        int wt;
        cin>>wt;
        weights.push_back(wt);
    }
    int bitmask = (1<<n)-1;
    vector<pair<int,int>>dp(bitmask+1,{-1,-1});
    cout<<solve(bitmask, weights, maxWeight,dp)<<endl;
    
	return 0;
}

