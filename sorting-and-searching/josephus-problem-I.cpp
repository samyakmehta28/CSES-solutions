#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){};
};

int main() {
    int n;
    cin>>n;
    vector<int>res;
    ListNode *head = new ListNode(0);
    ListNode *tail=head;
    for(int i=1;i<=n;i++){
        ListNode *temp = new ListNode(i);
        tail->next=temp;
        tail=tail->next;
    }
    tail->next=head->next;
    ListNode *prev=head->next;
    ListNode *curr=(head->next)->next;
    while(res.size()<n){
        res.push_back(curr->val);
        if(prev==curr){
            break;
        }
        else{
            ListNode *nex = curr->next;
            prev->next=nex;
            curr->next=NULL;
            delete(curr);
            prev=nex;
            curr=nex->next;
        }
    }
    for(auto ans: res){
        cout<<ans<<' ';
    }
    return 0;
}

