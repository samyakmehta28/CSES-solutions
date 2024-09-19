#include <bits/stdc++.h>
using namespace std;

int main() {
   int n,k;
   cin>>n>>k;
   vector<int>nums;
   for(int i=0;i<n;i++){
       int num;
       cin>>num;
       nums.push_back(num);
   }
   map<int,int>m;
   long long count=0;
   int j=0;
   for(int i=0;i<n;i++){
       m[nums[i]]++;
       while(j<i && m.size()>k){
           m[nums[j]]--;
           if(m[nums[j]]==0){
               m.erase(nums[j]);
           }
           j++;
       }
       count = count + (i-j+1);
   }
   cout<<count<<endl;
   return 0;
}
