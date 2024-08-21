#include <bits/stdc++.h>
using namespace std;



int main(){
   int n,m;
   cin>>n>>m;
   vector<tuple<int,int,int>>edges;
   for(int i=0;i<m;i++){
       int a,b,c;
       cin>>a>>b>>c;
       edges.push_back({a-1,b-1,c});
   }
   for(int i=0;i<n;i++){
       vector<long long>distance(n,LLONG_MAX);
       distance[i]=0;
       int count=0;
       int cycle_ele=-1;
       bool cycle=true;
       vector<int>parent(n,-1);
       while(count<n){
           bool any = false;
           for(auto t: edges){
               int a,b,c;
               tie(a,b,c) = t;
               if(distance[a]!=LLONG_MAX && distance[b]>distance[a]+c){
                   distance[b]=distance[a]+c;
                //   cout<<distance[b]<<' '<<c<<endl;
                   any=true;
                   cycle_ele=b;
                   parent[b]=a;
               }
           }
        //   cout<<i<<' '<<any<<endl;
           if(!any){
               cycle=false;
               break;
           }
           count++;
       }
       if(cycle){
           cout<<"YES"<<endl;
           vector<bool>visited(n,false);
           vector<int>temp;
           int curr=cycle_ele;
           while(curr!=-1){
               temp.push_back(curr);
               if(visited[curr]){
                   break;
               }
               visited[curr]=true;
               curr=parent[curr];
           }
           for(int i=temp.size()-1;i>=0;i--){
               cout<<temp[i]+1<<' ';
               if(temp[i]==curr && i!=temp.size()-1){
                   break;
               }
           }
           return 0;
           
       }
   }
   cout<<"NO"<<endl;
   return 0;
 
}