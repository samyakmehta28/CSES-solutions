#include <bits/stdc++.h>
using namespace std;

vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};

void dfs(int x, int y, vector<string>&grid, vector<vector<bool>>&visited){
    int n = grid.size();
    int m = grid[0].size();
    
    visited[x][y]=true;
    
    for(int k=0;k<4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx<0 || ny<0 || nx>=n || ny>=m || visited[nx][ny] || grid[nx][ny]=='#'){
            continue;
        }
        else{
            dfs(nx,ny,grid,visited);
        }
    }
}

int count_rooms(vector<string>&grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j]!='#'){
                dfs(i, j, grid, visited);
                ans++;
            }
        }
    }
    return ans;
}

int main() {
	int n,m;
	cin>>n>>m;
	vector<string>grid;
	for(int i=0;i<n;i++){
	    string curr;
	    cin>>curr;
	   // cout<<curr<<endl;
	    grid.push_back(curr);
	}
	int result = count_rooms(grid);
	cout<<result<<endl;
	return 0;
}
