#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>&a, pair<int,int>&b){
    if(a.second==b.second){
        a.first>b.first;
    }
    return (a.second<b.second);
}

int main() {
    int n;
    cin>>n;
    vector<pair<int,int>>movies;
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        movies.push_back({start,end});
    }
    sort(movies.begin(),movies.end(),comp);
    int time_available=0;
    int result=0;
    for(int i=0;i<n;i++){
        pair<int,int>movie = movies[i];
        if(movie.first>=time_available){
            time_available=movie.second;
            result++;
        }
        
    }
    cout<<result<<endl;
}

