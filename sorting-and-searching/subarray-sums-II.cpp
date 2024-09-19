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
    map<long long,long long>m;
    long long sum=0;
    m[0]++;
    long long count=0;
    for(int i=0;i<n;i++){
        sum=sum+nums[i];
        long long remove_sum = sum-target;
        if(m.find(remove_sum)!=m.end()){
            count=count+m[remove_sum];
        }
        m[sum]++;
    }
    cout<<count<<endl;
    return 0;
}
