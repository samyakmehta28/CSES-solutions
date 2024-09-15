#include <bits/stdc++.h>
using namespace std;

bool comp(tuple<int,int,int>&a, tuple<int,int,int>&b){
    if(get<0>(a)==get<0>(b)){
        return (get<1>(a)>get<1>(b));
    }
    return (get<0>(a)<get<0>(b));
}

int main() {
    int n;
    cin>>n;
    vector<tuple<int,int,int>>ranges;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        ranges.push_back({x,y,i});
    }
    sort(ranges.begin(),ranges.end(),comp);
    stack<int>st;
    vector<int>result1(n,0);
    vector<int>result2(n,0);
    for(int i=0;i<ranges.size();i++){
        auto range = ranges[i];
        int start = get<0>(range);
        int end = get<1>(range);
        int ind = get<2>(range);
        while(!st.empty() && start>get<1>(ranges[st.top()])){
            st.pop();
        }
        while(!st.empty() && end<=get<1>(ranges[st.top()])){
            result1[get<2>(ranges[st.top()])]=1;
            st.pop();
        }
        st.push(i);
    }
    for(auto res: result1){
        cout<<res<<' ';
    }
    cout<<endl;
    while(!st.empty()){
        st.pop();
    }
     for(int i=0;i<ranges.size();i++){
        auto range = ranges[i];
        int start = get<0>(range);
        int end = get<1>(range);
        int ind = get<2>(range);
        while(!st.empty() && end>get<1>(ranges[st.top()])){
            st.pop();
        }
        if(!st.empty()){
            result2[ind]=1;
        }
        st.push(i);
    }
    for(auto res: result2){
        cout<<res<<' ';
    }
    cout<<endl;
    
}

