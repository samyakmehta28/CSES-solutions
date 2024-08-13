#include <bits/stdc++.h>
using namespace std;

vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};
vector<char>dir{'U','R','L','D'};


bool dfs(int u, int parent, vector<vector<int>>&adj, vector<bool>&visited, vector<int>&path){
    visited[u]=true;
    path.push_back(u);
    for(auto v: adj[u]){
        if(!visited[v]){
            if(dfs(v,u,adj,visited,path)){
                return true;
            }
        }
        else if(v!=parent){
            path.push_back(v);
            return true;
        }
    }
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
	   adj[b-1].push_back(a-1);
	}
	
	vector<bool>visited(n,false);
	vector<int>res;
	for(int i=0;i<n;i++){
    	if(!visited[i]){
    	    vector<int>path;
    	    if(dfs(i,-1,adj,visited,path)){
    	        bool start=false;
    	        for(auto p:path){
    	            if(p==path.back()){
    	                start=true;
    	            }
    	            if(start){
    	                res.push_back(p+1);
    	            }
    	        }
    	        break;
    	    }
    	}
	}
	if(res.size()){
	    cout<<res.size()<<endl;
	    for(auto ans: res){
	        cout<<ans<<' ';
	    }
	    cout<<endl;
	    return 0;
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
