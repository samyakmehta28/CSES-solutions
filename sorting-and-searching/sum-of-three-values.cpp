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
    map<int,int>m;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int required = target-nums[i]-nums[j];
            if(m.find(required)!=m.end()){
                cout<<m[required]+1<<' '<<i+1<<' '<<j+1<<endl;
                return 0;
            }
        }
        if(m.find(nums[i])==m.end()){
            m[nums[i]]=i;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
