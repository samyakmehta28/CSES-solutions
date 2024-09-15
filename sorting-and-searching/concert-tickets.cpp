#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,m;
    cin>>n>>m;
    map<int,int>tickets;
    for(int i=0;i<n;i++){
        int price;
        cin>>price;
        tickets[price]++;
    }
    vector<int>customers;
    for(int i=0;i<m;i++){
        int price;
        cin>>price;
        customers.push_back(price);
        
    }
    for(int i=0;i<customers.size();i++){
        int customer = customers[i];
        auto it = tickets.upper_bound(customer);
        if(it==tickets.begin()){
            cout<<"-1"<<endl;
        }
        else{
            it--;
            int ticket = it->first;
            cout<<ticket<<endl;
            tickets[ticket]--;
            if(tickets[ticket]==0){
                tickets.erase(ticket);
            }
        }
    }
    return 0;
}

