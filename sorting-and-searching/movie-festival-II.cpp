#include <bits/stdc++.h>
using namespace std;
 
bool comp(pair<int,int>a, pair<int,int>b){
    if(a.second==b.second){
        return (a.first<b.first);
    }
    return (a.second<b.second);
}
 
int main() {
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>num;
    //long long sum=0;
    for(int i=0;i<n;i++){
        int ele1, ele2;
        cin>>ele1>>ele2;
        num.push_back({ele1,ele2});
        //sum=sum+ele;
    }
    sort(num.begin(),num.end(),comp);
    priority_queue<int,vector<int>,greater<int>>pq;
    map<int,int>last_t;
    last_t[0]=k;
    int i=0;
    int count=0;
    while(i<num.size()){
        while(!pq.empty() && num[i].first>=pq.top()){
            //cout<<pq.top()<<endl;
            last_t[pq.top()]++;
            pq.pop();
        }
        if(last_t.size()>0){
            //cout<<num[i].first<<' '<<num[i].second<<' '<<pq.size()<<endl;
            //last_t=num[i].first;
            auto it = last_t.upper_bound(num[i].first);
            if(it!=last_t.begin()){
                it--;
                last_t[it->first]--;
                pq.push(num[i].second);
                if(last_t[it->first]==0){
                    last_t.erase(it->first);
                }
                //cout<<num[i].second<<endl;
                count++;
            }
            
        }
        //cout<<i<<endl;
        i++;
    }
    cout<<count<<endl;
}
