#include <bits/stdc++.h>
using namespace std;

vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};
vector<char>dir{'U','R','L','D'};

int union_find(int v, vector<int>&parent){
    if(parent[v]==-1){
        return v;
    }
    return union_find(parent[v],parent);
}

void union_connect(int pa, int pb, vector<int>&parent, vector<int>&size){
    if(size[pa]>size[pb]){
        parent[pb]=pa;
        size[pa]+=size[pb];
    }
    else{
        parent[pa]=pb;
        size[pb]+=size[pa];
    }
}

int main() {
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>edges;
	for(int i=0;i<m;i++){
	   int a,b;
	   cin>>a>>b;
	   edges.push_back({a-1,b-1});
	}
	
	vector<int>parent(n,-1);
	vector<int>size(n,1);
	
	for(int i=0;i<edges.size();i++){
	    int a = edges[i].first;
	    int b = edges[i].second;
	    int pa = union_find(a,parent);
	    int pb = union_find(b,parent);
	    if(pa!=pb){
	        union_connect(pa,pb,parent,size);
	    }
	}
	vector<int>res;
	for(int i=0;i<parent.size();i++){
	    if(parent[i]==-1){
	        res.push_back(i);
	    }
	}
	cout<<res.size()-1<<endl;
	for(int i=1;i<res.size();i++){
	    cout<<res[i-1]+1<<' '<<res[i]+1<<endl;
	}
	
	return 0;
}
