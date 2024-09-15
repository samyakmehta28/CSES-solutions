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
    map<int,int>m;
    for(int i=0;i<n;i++){
        int num = nums[i];
        if(m.find(target-num)!=m.end()){
            cout<<m[target-num]+1<<' '<<i+1<<endl;
            return 0;
        }
        if(m.find(num)==m.end()){
            m[num]=i;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
   
}

