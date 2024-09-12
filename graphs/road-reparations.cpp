#include <bits/stdc++.h>
using namespace std;

bool comp(tuple<int,int,int>&a, tuple<int,int,int>&b){
    return (get<2>(a)<get<2>(b));
}

int union_find(int u, vector<int>&parent){
    if(parent[u]==-1){
        return u;
    }
    return union_find(parent[u],parent);
}

void union_connect(int u, int v, vector<int>&parent, vector<int>&size){
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
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int>>edges;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a-1,b-1,c});
    }
    vector<int>parent(n,-1);
    vector<int>size(n,1);
    sort(edges.begin(),edges.end(),comp);
    long long cost=0;
    int disconnectedComponents=n;
    for(auto e: edges){
        int u = get<0>(e);
        int v = get<1>(e);
        int c = get<2>(e);
        if(union_find(u,parent)!=union_find(v,parent)){
            union_connect(u,v,parent,size);
            cost=cost+c;
            disconnectedComponents--;
        }
    }
    if(disconnectedComponents!=1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<cost<<endl;
}

