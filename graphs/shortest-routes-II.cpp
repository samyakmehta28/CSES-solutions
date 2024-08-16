#include <bits/stdc++.h>
using namespace std;

vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};
vector<char>dir{'U','R','L','D'};


int main() {
	int n,m,q;
	cin>>n>>m>>q;
	vector<tuple<int,int,int>>edges;
	for(int i=0;i<m;i++){
	    int a,b,c;
	    cin>>a>>b>>c;
	    edges.push_back({a-1,b-1,c});
	}
	vector<vector<long long>>distance(n,vector<long long>(n,LLONG_MAX));
	for(int i=0;i<n;i++){
	    distance[i][i]=0;
	}
	for(auto p: edges){
	    int a,b,c;
	    tie(a,b,c)=p;
	    distance[a][b]=min(distance[a][b],(long long)c);
	    distance[b][a]=min(distance[b][a],(long long)c);
	}
	for(int k=0;k<n;k++){
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(distance[i][k]!=LLONG_MAX && distance[k][j]!=LLONG_MAX){
	                distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
	            }
	        }
	    }
	}
	for(int i=0;i<q;i++){
	    int a,b;
	    cin>>a>>b;
	    if(distance[a-1][b-1]==LLONG_MAX){
	        cout<<"-1"<<endl;
	        continue;
	    }
	    cout<<distance[a-1][b-1]<<endl;
	}
}
    
