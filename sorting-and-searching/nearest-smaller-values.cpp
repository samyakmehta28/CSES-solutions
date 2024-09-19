#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    stack<int>s;
    vector<int>res(n,0);
    for(int i=0;i<nums.size();i++){
        while(!s.empty() && nums[i]<=nums[s.top()]){
            s.pop();
        }
        if(!s.empty()){
            res[i]=s.top()+1;
        }
        s.push(i);
    }
    for(auto ans: res){
        cout<<ans<<' ';
    }
    
    return 0;
}
