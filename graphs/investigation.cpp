#include <bits/stdc++.h>
using namespace std;

int mod = pow(10,9)+7;

int main() {
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>>adj(n);
	for(int i=0;i<m;i++){
	    int a,b,c;
	    cin>>a>>b>>c;
	    adj[a-1].push_back({b-1,c});
	}
	vector<bool>visited(n,0);
	vector<int>ways(n,0);
	ways[0]=1;
	vector<long long>distance(n,LLONG_MAX);
	distance[0]=0;
	vector<int>min_flight(n,INT_MAX);
	vector<int>max_flight(n,0);
	min_flight[0]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
	pq.push({0,0});
	while(!pq.empty()){
	    auto d = (pq.top()).first;
	    int u = (pq.top()).second;
	    pq.pop();
	    if(visited[u]){
	        continue;
	    }
	    visited[u]=true;
	    for(auto p: adj[u]){
	        int v = p.first;
	        int cost = p.second;
	        if(visited[v]){
	            continue;
	        }
	        if(distance[v]>distance[u]+cost){
	            distance[v]=distance[u]+cost;
	            min_flight[v]=min_flight[u]+1;
	            max_flight[v]=max_flight[u]+1;
	            pq.push({distance[v],v});
	            ways[v]=ways[u];
	        }
	        else if(distance[v]==distance[u]+cost){
	            min_flight[v]=min(min_flight[v],min_flight[u]+1);
	            max_flight[v]=max(max_flight[v],max_flight[u]+1);
	            ways[v]+=ways[u];
	            ways[v]=ways[v]%mod;
	        }
	    }
	    
	}
	
	cout<<distance[n-1]<<' '<<ways[n-1]<<' '<<min_flight[n-1]<<' '<<max_flight[n-1]<<endl;

}
