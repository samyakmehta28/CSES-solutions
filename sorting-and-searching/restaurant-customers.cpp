#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<pair<int,int>>customers;
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        customers.push_back({start,end});
    }
    sort(customers.begin(),customers.end());
    priority_queue<int,vector<int>,greater<int>>pq;
    int result=0;
    for(int i=0;i<n;i++){
        pair<int,int>customer = customers[i];
        while(!pq.empty() && customer.first>pq.top()){
            pq.pop();
        }
        pq.push(customer.second);
        result=max(result,(int)pq.size());
    }
    cout<<result<<endl;
}

