#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>applicants;
    vector<int>apartments;
    for(int i=0;i<n;i++){
        int size;
        cin>>size;
        applicants.push_back(size);
    }
    for(int i=0;i<m;i++){
        int size;
        cin>>size;
        apartments.push_back(size);
    }
    sort(applicants.begin(),applicants.end());
    sort(apartments.begin(),apartments.end());
    int j=0;
    int count=0;
    for(int i=0;i<n;i++){
        while(j<m && apartments[j]<applicants[i]-k){
            j++;
        }
        if(j>=m){
            break;
        }
        if(apartments[j]>=applicants[i]-k && apartments[j]<=applicants[i]+k){
            count++;
            j++;
        }
    }
    cout<<count<<endl;
    
}

