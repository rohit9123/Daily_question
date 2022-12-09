#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<string.h>
#include<math.h>
#include<unordered_map>
#include<iomanip>
#include<unordered_set>
 
#define rep(i,x,n) for(int i=x;i<n;i++)
#define ll long long
#define fs first
#define ss second
#define mod 1000000007
#define pb push_back
#define in insert
#define pres(c,x) ((c).find(x)!=c.end());
#define lli long long int
#define vl vector<ll>
#define mp(a,b) make_pair(a,b)
 
 
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
using namespace std;
vector<vector<int> > component,graph;
vector<int> comp,visited,parent;
unordered_map<int,int> component_no;
unordered_map<int,int> pos;
int lift[200001][30];
int no=0;

// void dfs(int node,int par){
//     parent[node]=par;
//     visited[node]=1;
//     // cout<<node<<" ";÷
//     for(int a:graph[node]){
//         if(visited[a]==1){
//             vector<int> cycle;
            
//             int position=0;
//             while(node!=a){
//                 // cout<<node<<" "<<a<<endl;
//                 component_no[node]=no;
//                 // pos[node]=position++;
//                 cycle.push_back(node);
//                 node=parent[node];
//             }
//             // pos[a]=position++;
//             component_no[a]=no++;
//             cycle.push_back(a);
//             reverse(cycle.begin(),cycle.end());
//             for(int a:cycle){
//                 pos[a]=position++;
//             }
//             component.push_back(cycle);
//             break;
//         }else if(visited[a]==2){
//             continue;
//         }else{
//             dfs(a,node);
//         }
//     }
//     visited[node]=2;
// }

int main(){
    fast;
    int n,q;
    cin>>n>>q;
    graph.resize(n+1);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        lift[i+1][0]=a;
        graph[i+1].push_back(a);
    }
    for(int d=1;d<30;d++){
        for(int i=1;i<=n;i++){
            lift[i][d]=lift[lift[i][d-1]][d-1];
        }
    }
    visited.resize(n+1,0);
    parent.resize(n+1);
    // for(int i=1;i<=n;i++){
    //     if(visited[i]==0){
    //         dfs(i,-1);
    //     }
    // }
    
    while(q--){
        int node,t;
        cin>>node>>t;
        // if(component_no.find(node)!=component_no.end()){
        //     int comp_no=component_no[node];
        //     int position=pos[node];
        //     int size=component[comp_no].size();
        //     int index=(position+t)%size;
        //     cout<<component[comp_no][index]<<endl;
        // }else{
            for(int i=0;i<30;i++){
                if(t&(1<<i)){
                    node=lift[node][i];
                }
            }
            cout<<node<<endl;
        // }
    }
}