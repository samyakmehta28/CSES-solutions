#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<int>indeg(n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        indeg[b-1]++;
    }
    queue<int>q;
    vector<int>path;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        path.push_back(u+1);
        q.pop();
        for(auto v: adj[u]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
            }
        }
    }
    if(path.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(auto p:path){
        cout<<p<<' ';
    }
    return 0;
}