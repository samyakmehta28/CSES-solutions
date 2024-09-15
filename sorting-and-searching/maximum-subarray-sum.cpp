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
    long long max_sum=LLONG_MIN;
    long long curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum = curr_sum + nums[i];
        max_sum=max(curr_sum,max_sum);
        if(curr_sum<0){
            curr_sum=0;
        }
    }
    cout<<max_sum<<endl;
    return 0;
   
}

