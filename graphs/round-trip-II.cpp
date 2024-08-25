#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<int>&path, vector<bool>&visited, vector<bool>&inqueue, vector<vector<int>>&adj){
    visited[u]=true;
    inqueue[u]=true;
    path.push_back(u);
    for(auto v: adj[u]){
        if(!visited[v]){
            if(dfs(v,path,visited,inqueue, adj)){
                return true;
            }
        }
        else if(inqueue[v]){
            path.push_back(v);
            return true;
        }
    }
    inqueue[u]=false;
    path.pop_back();
    return false;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    vector<bool>visited(n,false);
    vector<bool>inqueue(n,false);
    vector<int>path;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(i,path,visited,inqueue,adj)){
                vector<int>ans;
                for(int i=path.size()-1;i>=0;i--){
                    ans.push_back(path[i]+1);
                    if(path[i]==path.back() && i!=path.size()-1){
                        break;
                    }
                }
                reverse(ans.begin(),ans.end());
                cout<<ans.size()<<endl;
                for(auto res:ans){
                    cout<<res<<' ';
                }
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}