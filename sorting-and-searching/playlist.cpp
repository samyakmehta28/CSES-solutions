#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>songs;
    for(int i=0;i<n;i++){
        int song;
        cin>>song;
        songs.push_back(song);
    }
    map<int,int>m;
    int start=0;
    int res=1;
    for(int i=0;i<n;i++){
        if(m.find(songs[i])!=m.end()){
            int j = m[songs[i]];
            while(start<=j){
                m.erase(songs[start]);
                start++;
            }
        }
        m[songs[i]]=i;
        res=max(res,i-start+1);
    }
    cout<<res<<endl;
   
}

