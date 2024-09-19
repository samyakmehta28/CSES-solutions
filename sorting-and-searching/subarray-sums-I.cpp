#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin>>n>>x;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    int count=0;
    int start=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+nums[i];
        while(start<i && sum>x){
            sum=sum-nums[start];
            start++;
        }
        if(sum==x){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
