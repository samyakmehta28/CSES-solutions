#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<pair<int,int>>processes;
    for(int i=0;i<n;i++){
        int duration,deadline;
        cin>>duration>>deadline;
        processes.push_back({duration, deadline});
    }
    sort(processes.begin(),processes.end());
    long long rewards=0;
    long long start_time=0;
    for(auto p: processes){
        rewards  +=  p.second-(start_time+p.first); 
        start_time = start_time+p.first;
    }
    cout<<rewards<<endl;
    return 0;
}
