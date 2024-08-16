#include <bits/stdc++.h>
using namespace std;

vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};
vector<char>dir{'U','R','L','D'};

void dijskrata(int s, vector<long long>&distance, vector<vector<pair<int,int>>>&adj){
    int n = distance.size();
    vector<bool>visited(n,false);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    distance[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u]){
            continue;
        }
        visited[u]=true;
        for(auto p: adj[u]){
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
}

int main() {
	int n,m;
	cin>>n>>m;
	vector<tuple<int,int,int>>edges;
	vector<vector<pair<int,int>>>adj(n);
	vector<vector<pair<int,int>>>radj(n);
	for(int i=0;i<m;i++){
	    int a,b,c;
	    cin>>a>>b>>c;
	    edges.push_back({a-1,b-1,c});
	    adj[a-1].push_back({b-1,c});
	    radj[b-1].push_back({a-1,c});
	}
	vector<long long>distance1(n,LLONG_MAX);
	vector<long long>distance2(n,LLONG_MAX);
	dijskrata(0,distance1,adj);
	dijskrata(n-1,distance2,radj);
	long long ans=LLONG_MAX;
	for(auto p:edges){
	    int a,b,c;
	    tie(a,b,c)=p;
	    if(distance1[a]!=LLONG_MAX && distance2[b]!=LLONG_MAX){
	        ans = min(ans,distance1[a]+distance2[b]+c/2);
	    }
	    
	}
	cout<<ans<<endl;
	
}
    
