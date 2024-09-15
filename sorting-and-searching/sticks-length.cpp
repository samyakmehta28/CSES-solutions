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
    sort(nums.begin(),nums.end());
    long long cost=0;
    int median_index = n/2;
    for(int i=0;i<n;i++){
        cost = cost + abs(nums[i]-nums[median_index]);
    }
    cout<<cost<<endl;
   
}

