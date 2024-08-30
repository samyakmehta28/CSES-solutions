#include <bits/stdc++.h>
using namespace std;


int dfs(int u, vector<vector<int>>&adj, vector<int>&distance, vector<int>&child, vector<bool>&visited){
    // cout<<u<<endl;
    if(visited[u]){
        return distance[u];
    }
    visited[u]=true;
    int max_d = INT_MIN;
    for(auto v: adj[u]){
        int d = dfs(v,adj,distance,child,visited);
        if(d!=INT_MIN && max_d<d){
            max_d=d;
            child[u]=v;
        }
    }
    if(max_d==INT_MIN){
        return distance[u];
    }
    return distance[u]=max_d+1;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    vector<bool>visited(n,false);
    vector<int>distance(n,INT_MIN);
    distance[n-1]=1;
    vector<int>child(n,-1);
    int d = dfs(0,adj,distance, child, visited);
    if(d==INT_MIN){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<d<<endl;
    int curr=0;
    while(curr!=-1){
        cout<<curr+1<<' ';
        curr=child[curr];
    }
    return 0;
}



