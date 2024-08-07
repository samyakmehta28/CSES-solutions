#include <bits/stdc++.h>
using namespace std;

vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};
vector<char>dir{'U','R','L','D'};

int bfs(pair<int,int>&start, pair<int,int>&end, vector<vector<char>>&grid, vector<vector<pair<int,int>>>&parent){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
    int i = start.first;
    int j = start.second;
    queue<pair<int,int>>q;
    q.push(start);
    distance[i][j]=0;
    visited[i][j]=true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny] || grid[nx][ny]=='#'){
                continue;
            }
            distance[nx][ny]=distance[x][y]+1;
            visited[nx][ny]=true;
            q.push({nx,ny});
            parent[nx][ny]={x,y};
        }
    }
    if(!visited[end.first][end.second]){
        return -1;
    }
    return distance[end.first][end.second];
	
}


int main() {
	int n,m;
	cin>>n>>m;
	vector<vector<char>>grid(n);
	pair<int,int>start;
	pair<int,int>end;
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        char curr;
    	    cin>>curr;
    	    grid[i].push_back(curr);
    	    if(grid[i][j]=='A'){
    	        start={i,j};
    	    }
    	    if(grid[i][j]=='B'){
    	        end={i,j};
    	    }
	        
	    }
	}
	
	vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));
	int dist = bfs(start, end, grid, parent);
	if(dist==-1){
	    cout<<"NO"<<endl;
	    return 0;
	}
	cout<<"YES"<<endl;
	cout<<dist<<endl;
	string path = "";
	pair<int,int>curr = end;
	while(curr!=start){
	    pair<int,int>par = parent[curr.first][curr.second];
	    int d_x = par.first-curr.first;
	    int d_y = par.second - curr.second;
	    if(d_x==-1){
	        path.push_back('D');
	    }
	    else if(d_x==1){
	        path.push_back('U');
	    }
	    else if(d_y==-1){
	        path.push_back('R');
	    }
	    else{
	        path.push_back('L');
	    }
	    curr=par;
	}
	reverse(path.begin(),path.end());
	cout<<path<<endl;
	return 0;
}
