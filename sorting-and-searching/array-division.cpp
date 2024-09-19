#include <bits/stdc++.h>
using namespace std;

int checkFeasible(long long target, vector<int>&nums){
    int count=1;
    long long subarraySum=0;
    for(auto num: nums){
        subarraySum = subarraySum+num;
        if(subarraySum>target){
            subarraySum=num;
            count++;
        }
    }
    return count;
}
int main() {
    int n,k;
    cin>>n>>k;
    vector<int>nums;
    long long sum=0;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
        sum=sum+num;
    }
    long long l=*max_element(nums.begin(),nums.end());
    long long h=sum;
    long long res=h;
    while(l<=h){
        long long mid = l + (h-l)/2;
        if(checkFeasible(mid, nums)<=k){
            res=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<res<<endl;
    return 0;
}
