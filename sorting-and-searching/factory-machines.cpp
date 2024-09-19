#include <bits/stdc++.h>
using namespace std;

long long findProductsProduced(vector<int>&machines, long long time_alloted){
    long long count=0;
    for(auto machine:machines){
        count += time_alloted/machine;
    }
    return count;
}

int main() {
    int n,products;
    cin>>n>>products;
    vector<int>machines;
    for(int i=0;i<n;i++){
        int machine;
        cin>>machine;
        machines.push_back(machine);
    }
    long long best_machine = (long long)*min_element(machines.begin(),machines.end());
    long long l=0;
    long long h=best_machine*products;
    long long result=h;
    while(l<=h){
        long long mid = l + (h-l)/2;
        long long products_produced = findProductsProduced(machines,mid);
        if(products_produced>=products){
            result=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<result<<endl;
}
