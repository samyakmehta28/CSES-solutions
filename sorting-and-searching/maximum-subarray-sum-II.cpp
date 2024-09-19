#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }
   
   vector<long long>prefix(n+1,0);
   for(int i=1;i<=n;i++){
       prefix[i]=prefix[i-1]+nums[i-1];
   }
   long long max_sum=prefix[a];
//   for(auto p: prefix){
//       cout<<p<<' ';
//   }
//   cout<<endl;
   deque<int>dq;
   for(int i=a;i<=n;i++){
      if(i>b){
        if(dq.front()==i-b-1){
            dq.pop_front();
        }
      }
     while(!dq.empty() && prefix[dq.back()]>=prefix[i-a]){
         dq.pop_back();
     }
     dq.push_back(i-a);
      max_sum = max(max_sum, prefix[i]-prefix[dq.front()]);
   }
  cout<<max_sum<<endl;
	return 0;
}