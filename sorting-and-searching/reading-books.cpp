#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    long long total_time=0;
    long long max_time=0;
    for(int i=0;i<n;i++){
        long long book;
        cin>>book;
        max_time=max(book,max_time);
        total_time=total_time+book;
    }
    if(total_time-max_time<max_time){
        cout<<max_time*2<<endl;
        return 0;
    }
    cout<<total_time<<endl;
    return 0;
}
