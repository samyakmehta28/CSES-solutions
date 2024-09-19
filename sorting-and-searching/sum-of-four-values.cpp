#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,target;
    cin>>n>>target;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    map<int,pair<int,int>>m;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int required = target-nums[i]-nums[j];
            //cout<<i<<' '<<j<<' '<<required<<endl;
            if(m.find(required)!=m.end()){
                if(m[required].first!=i && m[required].second!=i && m[required].second!=j && m[required].first!=j){
                    cout<<m[required].first+1<<' '<<m[required].second+1<<' '<<i+1<<' '<<j+1<<endl;
                    return 0;
                }
            }
            if(m.find(nums[i]+nums[j])==m.end()){
                m[nums[i]+nums[j]]={i,j};
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
