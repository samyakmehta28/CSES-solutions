#include <bits/stdc++.h>
using namespace std;


int union_find(int u, vector<int>&parent){
    if(parent[u]==-1){
        return u;
    }
    return union_find(parent[u],parent);
}

int union_connect(int u, int v, vector<int>&parent, vector<int>&size){
    int p1 = union_find(u,parent);
    int p2 = union_find(v,parent);
    
    if(size[p1]<size[p2]){
        size[p2]=size[p2]+size[p1];
        parent[p1]=p2;
    }
    else{
        size[p1]=size[p2]+size[p1];
        parent[p2]=p1;
    }
    return max(size[p1],size[p2]);
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
    int largestComponentSize=1;
    int disconnectedComponents=n;
    for(auto e: edges){
        int u = e.first;
        int v = e.second;
        if(union_find(u,parent)!=union_find(v,parent)){
            largestComponentSize=max(largestComponentSize,union_connect(u,v,parent,size));
            disconnectedComponents--;
        }
        cout<<disconnectedComponents<<' '<<largestComponentSize<<endl;
    }
    
    
}

