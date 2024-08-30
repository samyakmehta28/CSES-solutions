#include <bits/stdc++.h>
using namespace std;

int mod = pow(10,9)+7;

int dfs(int u, vector<vector<int>>&adj, vector<int>&distance, vector<bool>&visited){
    if(visited[u]){
        return distance[u];
    }
    visited[u]=true;
    for(auto v: adj[u]){
        distance[u]+= dfs(v,adj,distance,visited);
        distance[u]=distance[u]%mod;
    }
    return distance[u];
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
    vector<int>distance(n,0);
    distance[n-1]=1;
    int d = dfs(0,adj,distance, visited);
    cout<<d<<endl;
    return 0;
}



