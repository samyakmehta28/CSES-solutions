#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	int count=0;
	while(n){
	    int max_digit=-1;
	    int curr_num = n;
	    while(curr_num){
	        max_digit=max(max_digit,curr_num%10);
	        curr_num = curr_num/10;
	    }
	    n=n-max_digit;
	    count++;
	}
	cout<<count<<endl;
	return 0;
}
