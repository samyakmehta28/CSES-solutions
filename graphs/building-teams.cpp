#include <bits/stdc++.h>
using namespace std;

vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};
vector<char>dir{'U','R','L','D'};


bool dfs(int u, vector<vector<int>>&adj, vector<bool>&visited, vector<int>&color){
    for(auto v: adj[u]){
        if(!visited[v]){
            visited[v]=true;
            color[v]=!color[u];
            if(!dfs(v,adj,visited,color)){
                return false;
            }
        }
        else if(color[v]==color[u]){
            return false;
        }
    }
    return true;
}



int main() {
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n);
	for(int i=0;i<m;i++){
	   int a,b;
	   cin>>a>>b;
	   adj[a-1].push_back(b-1);
	   adj[b-1].push_back(a-1);
	}
	
	vector<int>color(n,-1);
	vector<bool>visited(n,false);
	for(int i=0;i<n;i++){
    	if(!visited[i]){
    	    visited[i]=true;
    	    color[i]=0;
    	    if(!dfs(i,adj,visited,color)){
    	        cout<<"IMPOSSIBLE"<<endl;
    	        return 0;
    	    }
    	}
	}
	for(auto c: color){
	    cout<<c+1<<' ';
	}
	cout<<endl;
	return 0;
}
