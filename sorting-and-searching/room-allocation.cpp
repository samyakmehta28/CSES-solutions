#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<tuple<int,int,int>>customers;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        customers.push_back({x,y,i});
    }
    sort(customers.begin(),customers.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    set<int>rooms;
    int roomNo=0;
    vector<int>res(n,0);
    for(int i=0;i<customers.size();i++){
        auto customer = customers[i];
        while(!pq.empty() && get<0>(customer)>pq.top().first){
            rooms.insert(pq.top().second);
            pq.pop();
        }
        if(rooms.size()==0){
            roomNo++;
            rooms.insert(roomNo);
        }
        int available_room = *rooms.begin();
        res[get<2>(customer)]=available_room;
        rooms.erase(available_room);
        pq.push({get<1>(customer),available_room});
    }
    cout<<roomNo<<endl;
    for(auto ans: res){
        cout<<ans<<' ';
    }
    cout<<endl;
    
}

