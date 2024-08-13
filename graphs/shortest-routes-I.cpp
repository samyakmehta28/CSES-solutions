#include <bits/stdc++.h>
using namespace std;

vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};
vector<char>dir{'U','R','L','D'};


int main() {
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>>adj(n);
	for(int i=0;i<m;i++){
	    int a,b,c;
	    cin>>a>>b>>c;
	    adj[a-1].push_back({b-1,c});
	}
    vector<int>visited(n,false);
    vector<long long>distance(n,LLONG_MAX);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    distance[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        
        if(visited[u]){
            continue;
        }
        
        visited[u]=true;
        
        for(auto p : adj[u]){
            int v = p.first; 
            int cost = p.second;
            if(!visited[v]){
                if(distance[v]>distance[u]+cost){
                    distance[v]=distance[u]+cost;
                    pq.push({distance[v],v});
                }
            }
        }
    }
    
    for(auto d: distance){
        cout<<d<<' ';
    }
    cout<<endl;
    return 0;
}
