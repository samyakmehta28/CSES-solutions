#include <bits/stdc++.h>
using namespace std;

long long dp[20][10][2][2];

long long solve(int ind, string&num, bool leadingZeroes, bool limit, int prevDigit){
    if(ind==num.size()){
        return 1;
    }
    if(prevDigit!=-1 && dp[ind][prevDigit][leadingZeroes][limit]!=-1){
    //   cout<<ind<<endl;
        return dp[ind][prevDigit][leadingZeroes][limit];
    }
    int lb=0;
    int ub=9;
    if(limit){
        ub=(int)(num[ind]-'0');
    }
    long long ans=0;
    // cout<<lb<<' '<<ub<<endl;
    for(int i=lb;i<=ub;i++){
        if(i==prevDigit && !leadingZeroes){
            continue;
        }
        ans = ans + solve(ind+1,num,(leadingZeroes && (i==0)), (limit && (i==ub)), i);
    }
    return dp[ind][prevDigit][leadingZeroes][limit]=ans;
}
 
int main() {
    long long a,b;
    cin>>a>>b;
    memset(dp, -1, sizeof dp);
    string num1 = to_string(b);
    //cout<<num1<<endl;
    long long count1 = solve(0,num1,1,1,-1);
    memset(dp, -1, sizeof dp);
    string num2 = to_string(a-1);
    long long count2 = solve(0,num2,1,1,-1);
    cout<<count1-count2<<endl;
    
	return 0;
}

