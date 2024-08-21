#include <bits/stdc++.h>
using namespace std;



int main(){
   int n,m,k;
   cin>>n>>m>>k;
   vector<vector<pair<int,int>>>adj(n);
   for(int i=0;i<m;i++){
       int a,b,c;
       cin>>a>>b>>c;
       adj[a-1].push_back({b-1,c});
   }
   
        
    vector<int>visited(n,0);
    vector<long long>res;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({0,0});
    while(!pq.empty()){
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if(visited[u]>=k){
            if(u==n-1){
                break;
            }
            continue;
        }
        if(u==n-1){
            res.push_back(d);
        }
        visited[u]++;
        for(auto p:adj[u]){
            int v = p.first;
            int c = p.second;
            if(visited[v]<k){
                pq.push({d+c, v});
            }
        }
    }
    for(auto r:res){
        cout<<r<<' ';
    }
    return 0;
    
}