#include <bits/stdc++.h>
using namespace std;

vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};
vector<char>dir{'U','R','L','D'};

bool dfs(int u, vector<bool>&visited, vector<vector<int>>&adj, set<int>&cycle_part){
    visited[u]=true;
    if(cycle_part.find(u)!=cycle_part.end()){
        return true;
    }
    for(auto v: adj[u]){
        if(!visited[v]){
            if(dfs(v,visited,adj,cycle_part)){
                return true;
            }
        }
    }
    return false;
}


int main() {
	int n,m;
	cin>>n>>m;
	vector<tuple<int,int,int>>edges;
	vector<vector<int>>radj(n);
	for(int i=0;i<m;i++){
	    int a,b,c;
	    cin>>a>>b>>c;
	    edges.push_back({a-1,b-1,c});
	    radj[b-1].push_back(a-1);
	}
	vector<long long>distance(n,LLONG_MIN);
	distance[0]=0;
	int i=1;
	bool cycle=true;
	set<int>cycle_part;
	while(i<=n){
	    bool any = false;
	    cycle_part.clear();
	    for(auto p:edges){
	        int a,b,c;
	        tie(a,b,c)=p;
	        if(distance[a]!=LLONG_MIN && distance[a]+c>distance[b]){
	            distance[b]=min(LLONG_MAX,distance[a]+c);
	            cycle_part.insert(b);
	            any=true;
	        }
	    }
	    if(!any){
	        cycle=false;
	        break;
	    }
	    i++;
	}
	if(cycle){
	    vector<bool>visited(n,false);
	    if(dfs(n-1,visited,radj,cycle_part)){
	        cout<<"-1"<<endl;
	        return 0;
	    }
	    
	    
	}
	
	cout<<distance[n-1]<<endl;
	return 0;
}
    
