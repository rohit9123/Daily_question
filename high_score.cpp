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
struct edge{
    int u,v,w;

};
vector<int> vis,vis2;


void dfs(vector<vector<int> > &graph,int u,vector<int>&vis){
    vis[u]=1;
    for(auto v:graph[u]){
        if(!vis[v]){
            dfs(graph,v,vis);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n+1);
    vector<vector<int> > graph2(n+1);
    vector<edge> arr(m);
    vis.resize(n+1,0);
    vis2.resize(n+1,0);
    for(int i=0;i<m;i++){
        cin>>arr[i].u>>arr[i].v>>arr[i].w;
        graph[arr[i].u].pb(arr[i].v);
        graph2[arr[i].v].pb(arr[i].u);
        arr[i].w=-1*arr[i].w;
    }
    dfs(graph,1,vis);
    dfs(graph2,n,vis2);
    vector<long long> dist(n+1,1e17);
    vector<long long> prev(n+1,1e17);
    dist[1]=0;
    bool flag2=false;
    for(int i=0;i<n-1;i++){
        
        for(int j=0;j<m;j++){
            if(dist[arr[j].u]!=1e17){
                dist[arr[j].v]=min(dist[arr[j].v],dist[arr[j].u]+arr[j].w);
            }
        }
        
        for(int i=1;i<=n;i++){
            prev[i]=dist[i];
            
        }
        
    }
    unordered_set<int> node;
    for(int j=0;j<m;j++){
       
        if(dist[arr[j].u]!=1e17){
            if(dist[arr[j].v]>dist[arr[j].u]+arr[j].w&&vis[arr[j].v]&&vis2[arr[j].v]){
                // node.insert(arr[j].v);
                flag2=true;
                // break;
            }
        }
    }
    
    if(flag2){
       
        cout<<-1<<endl;
    }else{
        
        cout<<-1*dist[n]<<endl;
    }
    


}