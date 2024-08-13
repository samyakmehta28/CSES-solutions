#include <bits/stdc++.h>
using namespace std;

vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};
vector<char>dir{'U','R','L','D'};


bool bfs(vector<string>&grid, string &path){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));
    queue<tuple<int,int,int>>q;
    pair<int,int>start;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                start={i,j};
                visited[i][j]=true;
                distance[i][j]=0;
            }
            else if(grid[i][j]=='M'){
                q.push({i,j,2});
                visited[i][j]=true;
            }
        }
    }
    q.push({start.first,start.second,1});
    while(!q.empty()){
        int x,y,v_id;
        tie(x,y,v_id)=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx<0 || ny<0 || nx>=n || ny>=m || visited[nx][ny] || grid[nx][ny]!='.'){
                continue;
            }
            visited[nx][ny]=true;
            q.push({nx,ny,v_id});
            if(v_id==1){
                distance[nx][ny]=distance[x][y]+1;
                parent[nx][ny]={x,y};
            }
            q.push({nx,ny,v_id});
        }
    }
    
    pair<int,int>end={-1,-1};
    int min_d = INT_MAX;
    for(int i=0;i<n;i++){
        if(distance[i][0]!=INT_MAX){
            if(min_d>distance[i][0]){
                min_d=distance[i][0];
                end ={i,0};
            }
        }
        if(distance[i][m-1]!=INT_MAX){
            if(min_d>distance[i][m-1]){
                min_d=distance[i][m-1];
                end ={i,m-1};
            }
        }
    }
    for(int j=0;j<m;j++){
        if(distance[0][j]!=INT_MAX){
            if(min_d>distance[0][j]){
                min_d=distance[0][j];
                end ={0,j};
            }
        }
        if(distance[n-1][j]!=INT_MAX){
            if(min_d>distance[n-1][j]){
                min_d=distance[n-1][j];
                end ={n-1,j};
            }
        }
    }
    
    pair<int,int>curr = end;
    if(curr.first==-1 || curr.second==-1){
        return false;
    }
    while(parent[curr.first][curr.second]!=make_pair(-1,-1)){
        pair<int,int>par = parent[curr.first][curr.second];
        int dx = curr.first - par.first;
        int dy = curr.second - par.second;
        if(dx==1){
            path.push_back('D');
        }
        else if(dx==-1){
            path.push_back('U');
        }
        else if(dy==1){
            path.push_back('R');
        }
        else{
            path.push_back('L');
        }
        curr=par;
    }
    return true;
    
}



int main() {
	int n,m;
	cin>>n>>m;
	vector<string>grid;
	for(int i=0;i<n;i++){
	    string s;
	    cin>>s;
	 
	    grid.push_back(s);
	}
    string path = "";
    bool possible = bfs(grid,path);
    if(!possible){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<path.size()<<endl;
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i];
    }
    cout<<endl;
	
	
	return 0;
}
