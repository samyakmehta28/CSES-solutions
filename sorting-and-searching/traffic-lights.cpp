#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    map<int,int>m;
    set<int>pos;
    pos.insert(0);
    pos.insert(n);
    m[n]++;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        auto it = pos.upper_bound(x);
        auto it1 = it;
        it--;
        auto it2 = it;
        int curr_dist = *it1-*it2;
        m[curr_dist]--;
        if(m[curr_dist]<=0){
            m.erase(curr_dist);
        }
        int new_dist1 = x-*it2;
        int new_dist2 = *it1-x;
        m[new_dist2]++;
        m[new_dist1]++;
        pos.insert(x);
        cout<<m.rbegin()->first<<endl;
    }
    
   
}

