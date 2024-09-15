#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<long long>nums;
    for(int i=0;i<n;i++){
        long long num;
        cin>>num;
        nums.push_back(num);
        
    }
    sort(nums.begin(),nums.end());
    long long ans=0;
    for(int i=0;i<n;i++){
        if(nums[i]>ans+1){
            cout<<ans+1<<endl;
            return 0;
        }
        ans = ans + nums[i];
    }
    cout<<ans+1<<endl;
   return 0;
}

