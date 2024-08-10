#include <bits/stdc++.h>
using namespace std;

vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};
vector<char>dir{'U','R','L','D'};

void bfs(vector<vector<int>>&adj, vector<int>&parent, vector<bool>&visited, vector<int>&distance){
    distance[0]=1;
    visited[0]=true;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!visited[v]){
                distance[v]=distance[u]+1;
                visited[v]=true;
                q.push(v);
                parent[v]=u;
            }
        }
    }
    return;
    
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
	
	vector<int>parent(n,-1);
	vector<bool>visited(n,false);
	vector<int>distance(n,INT_MAX);
	bfs(adj,parent,visited,distance);
	if(!visited[n-1]){
	    cout<<"IMPOSSIBLE"<<endl;
	    return 0;
	}
	cout<<distance[n-1]<<endl;
	vector<int>res;
	int curr = n-1;
	while(curr!=-1){
	    res.push_back(curr+1);
	    curr=parent[curr];
	}
	reverse(res.begin(),res.end());
	for(auto ans:res){
	    cout<<ans<<' ';
	}
	cout<<endl;
	return 0;
}
