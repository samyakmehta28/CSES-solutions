#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int>nums;
    unordered_map<int,int>rev_nums;
    rev_nums[0]=-1;
    rev_nums[n+1]=n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
        rev_nums[num]=i;
    }
    
    int res=1;
    for(int i=1;i<=n;i++){
        if(rev_nums[i]<rev_nums[i-1]){
            res++;
        }
       
    }
    for(int i=0;i<k;i++){
        int ind1,ind2;
        cin>>ind1>>ind2;
        ind1--;
        ind2--;
        if(ind1==ind2){
            cout<<res<<endl;
            continue;
        }
        if(ind1>ind2){
            swap(ind1,ind2);
        }
        if(ind1==ind2+1){
            if(nums[ind2]==nums[ind1]+1){
                res++;
            }
            else if(nums[ind2]==nums[ind1]-1){
                res--;
            }
        }
        else{
            int pre_ind2 = rev_nums[nums[ind2]-1];
            if(pre_ind2>=ind1 && pre_ind2<ind2){
                res++;
            }
            int post_ind2 = rev_nums[nums[ind2]+1];
            if(post_ind2>=ind1 && post_ind2<ind2){
                res--;
            }
            int pre_ind1 = rev_nums[nums[ind1]-1];
            if(pre_ind1>ind1 && pre_ind1<ind2){
                res--;
            }
            int post_ind1 = rev_nums[nums[ind1]+1];
            if(post_ind1>ind1 && post_ind1<ind2){
                res++;
            }
        }
        cout<<res<<endl;
        rev_nums[nums[ind1]]=ind2;
        rev_nums[nums[ind2]]=ind1;
        swap(nums[ind1],nums[ind2]);
    }
    return 0;
}

