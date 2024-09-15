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
    vector<int>tower_top;
    tower_top.push_back(nums[0]);
    for(int i=1;i<n;i++){
        int ind = upper_bound(tower_top.begin(),tower_top.end(),nums[i])-tower_top.begin();
        if(ind==tower_top.size()){
            tower_top.push_back(nums[i]);
        }
        else{
            tower_top[ind]=nums[i];
        }
        
    }
    cout<<tower_top.size()<<endl;
   
}

