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
   map<int,long long>m;
   m[0]++;
   int sum=0;
   long long count=0;
   for(int i=0;i<n;i++){
       sum = sum + nums[i];
       sum = sum%n;
       sum = (sum+n)%n;
       if(m.find(sum)!=m.end()){
           count=count+m[sum];
       }
       m[sum]++;
   }
   cout<<count<<endl;
   return 0;
}
