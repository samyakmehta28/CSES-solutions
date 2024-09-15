#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>nums(n,-1);
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums[num-1]=i;
    }
    
    vector<int>iterations(n,1);
    for(int i=1;i<n;i++){
        if(nums[i]>nums[i-1]){
            iterations[i]=iterations[i-1];
        }
        else{
            iterations[i]=iterations[i-1]+1;
        }
    }
    cout<<iterations[n-1]<<endl;
    return 0;
}

