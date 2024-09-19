#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n,k;
    cin>>n>>k;
    vector<int>nums;
    long long sum_max=0;
    long long sum_min=0;
    //long long sum=0;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        nums.push_back(ele);
        //sum=sum+ele;
    }
    set<pair<int,int>>pq_max;
    set<pair<int,int>>pq_min;
    //int balance=0;
    for(int i=0;i<k;i++){
        pq_max.insert({nums[i],i});
        sum_max=sum_max+nums[i];
    }
    for(int i=0;i<k/2;i++){
        pq_min.insert(*pq_max.rbegin());
        sum_max=sum_max-pq_max.rbegin()->first;
        sum_min=sum_min+pq_max.rbegin()->first;
        pq_max.erase(*pq_max.rbegin());
    }
    vector<long long>costs;
    for(int i=k;i<nums.size();i++){
        // cout<<i<<endl;
        long long median = (long long)pq_max.rbegin()->first;
        long long cost = llabs(sum_max - (k/2 + k%2) * median) + llabs(sum_min - k/2 * median);
        costs.push_back(cost);
        int balance=0;
        int numToRemove = nums[i-k];
        if(pq_max.find({numToRemove,i-k})!=pq_max.end()){
            pq_max.erase({numToRemove,i-k});
            sum_max = sum_max - numToRemove;
            balance--;
        }
        else{
            pq_min.erase({numToRemove,i-k});
            sum_min = sum_min - numToRemove;
            balance++;
        }
        // cout<<"here"<<endl;
        int num = nums[i];
        // cout<<pq_max.size()<<endl;
        if(pq_max.size() && pq_max.rbegin()->first>=num){
            pq_max.insert({num,i});
            sum_max=sum_max + num;
            balance++;
        }
        else{
            pq_min.insert({num,i});
            sum_min=sum_min + num;
            balance--;
        }
        // cout<<"here"<<endl;
        if(balance>0){
            pq_min.insert(*pq_max.rbegin());
            sum_min = sum_min + pq_max.rbegin()->first;
            sum_max = sum_max - pq_max.rbegin()->first;
            pq_max.erase(*pq_max.rbegin());
        }
        else if(balance<0){
            pq_max.insert(*pq_min.begin());
            sum_min = sum_min - pq_min.begin()->first;
            sum_max = sum_max + pq_min.begin()->first;
            pq_min.erase(*pq_min.begin());
        }
    }
    long long median = (long long)pq_max.rbegin()->first;
    long long cost = llabs(sum_max - (k/2 + k%2) * median) + llabs(sum_min - k/2 * median);
    costs.push_back(cost);
    for(int i=0;i<costs.size();i++){
        cout<<costs[i]<<' ';
    }
    cout<<endl;
	return 0;
}