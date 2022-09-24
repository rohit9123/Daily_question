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
vector<long long> dist;
void findshortestpath(vector<vector<pair<int,int> > >&graph){
    int n=graph.size();
    dist.resize(n);
    for(int i=0;i<n;i++){
        dist[i]=1e17;
    }
    priority_queue<pair<long long,long>,vector<pair<long,long> >,greater<pair<long long,long long> > > pq;
    pq.push(make_pair(0,1));
    while(pq.size()){
        pair<long long,long long> p=pq.top();
        pq.pop();
        
        int u=p.second;
        if(dist[u]<p.first)continue;
        dist[u]=p.first;
        for(int i=0;i<graph[u].size();i++){
            if(dist[graph[u][i].first]>dist[u]+graph[u][i].second){
                
                pq.push(make_pair(dist[u]+graph[u][i].second,graph[u][i].first));
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
    }
    findshortestpath(graph);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}