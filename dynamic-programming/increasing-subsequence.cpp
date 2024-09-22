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
    vector<int>lis;
    for(int i=0;i<nums.size();i++){
        int ind = lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
        if(ind==lis.size()){
            lis.push_back(nums[i]);
        }
        else{
            lis[ind]=nums[i];
        }
    }
    cout<<lis.size()<<endl;
    
	return 0;
}

