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
vector<vector<int> > graph,graph2;
vector<int> vis,vis2,parent;
vector<int> cycle;
int n,m;
// vector<vector<int> > graph;
void dfs(int node,int par=-1){
    vis[node]=1;
    parent[node]=par;
    for(auto child:graph[node]){
        if(vis[child]==1){
            cycle.pb(child);
            while(node!=child){
                cycle.pb(node);
                node=parent[node];
            }
            cycle.push_back(child);
            reverse(cycle.begin(),cycle.end());
            cout<<cycle.size()<<endl;
            for(auto x:cycle){
                cout<<x<<" ";
            }
            exit(0);
        }else if(vis[child]==0){
            dfs(child,node);
        }else if(vis[child]==2){
            continue;
        }
    }
    vis[node]=2;
}

int main(){
    cin>>n>>m;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    vis.resize(n+1,0);
    vis2.resize(n+1,0);
    parent.resize(n+1,-1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout<<"IMPOSSIBLE";
}
