#include <bits/stdc++.h>
using namespace std;

bool comp(tuple<int,int,int>&a, tuple<int,int,int>&b){
    return (get<1>(a)<get<1>(b));
}
 
int main() {
    int n;
    cin>>n;
    vector<tuple<int,int,int>>projects;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        projects.push_back({a,b,c});
    }
    sort(projects.begin(),projects.end(),comp);
    vector<int>endpts;
    vector<long long>dp(n+1,0);
    for(int i=1;i<=n;i++){
        int a,b,c;
        tie(a,b,c) = projects[i-1];
        endpts.push_back(b);
        auto ind = lower_bound(endpts.begin(),endpts.end(),a)-endpts.begin();
        dp[i]=max(dp[i-1],dp[ind]+c);
    }
    cout<<dp[n]<<endl;
    
	return 0;
}

