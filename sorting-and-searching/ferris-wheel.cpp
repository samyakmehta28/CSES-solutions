#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    map<int,int>weights;
    for(int i=0;i<n;i++){
        int wt;
        cin>>wt;
        weights[wt]++;
    }
    
    int gandolas=0;
    while(weights.size()){
        gandolas++;
        int child1 = (weights.begin())->first;
        weights[child1]--;
        if(weights[child1]==0){
            weights.erase(child1);
        }
        auto it = weights.upper_bound(k-child1);
        if(it==weights.begin()){
            continue;
        }
        else{
            it--;
            int child2 = it->first;
            weights[child2]--;
            if(weights[child2]==0){
                weights.erase(child2);
            }
        }
    }
    cout<<gandolas<<endl;
}

