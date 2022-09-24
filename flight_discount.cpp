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
vector<vector<pair<long,long> > > graph,graph2;
vector<long> dist;
struct edge{
    int u,v,w;

};


int main(){
    fast;
    int n,m;
    cin>>n>>m;
    vector<edge > arr(m);
    graph.resize(n+1);
    graph2.resize(n+1);
    dist.resize(n+1,1e17);
    for(int i=0;i<m;i++){
        long  u,v,w;
        cin>>u>>v>>w;
        graph[u].pb(mp(v,w));
        graph2[v].pb(mp(u,w));
        arr[i].u=u;
        arr[i].v=v;
        arr[i].w=w;
        
    }
    priority_queue<pair<long,int>,vector<pair<long,int> >,greater<pair<long,int> > > pq;
    pq.push(mp(0,1));
    while(pq.size()){
        pair<long,long> p=pq.top();
        pq.pop();
        int u=p.second;
        if(dist[u]<p.first)continue;
        dist[u]=p.first;
        for(int i=0;i<graph[u].size();i++){
            if(dist[graph[u][i].first]>dist[u]+graph[u][i].second){
                pq.push(mp(dist[u]+graph[u][i].second,graph[u][i].first));
            }
        }
    }
    vector<long> dist2(dist.begin(),dist.end());
    dist.clear();
    dist.resize(n+1,1e17);
    pq.push(mp(0,n));
    while(pq.size()){
        pair<long,long> p=pq.top();
        pq.pop();
        int u=p.second;
        if(dist[u]<p.first)continue;
        dist[u]=p.first;
        for(int i=0;i<graph2[u].size();i++){
            if(dist[graph2[u][i].first]>dist[u]+graph2[u][i].second){
                pq.push(mp(dist[u]+graph2[u][i].second,graph2[u][i].first));
            }
        }
    }
    long ans=dist2[n];
    for(int i=0;i<m;i++){
        ans=min(ans,dist2[arr[i].u]+dist[arr[i].v]+arr[i].w/2);
    }
    // cout<<ans<<endl;
    
    cout<<ans<<endl;

}