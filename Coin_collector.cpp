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
vector<vector<long long> > graph,reverse_graph;
vector<vector<long long> > rev_graph,component;
vector<long long> coin,group;
vector<long long> path,visited,comp;
vector<long long>comp_no;
long long dp[200001];
void dfs(int node){
    visited[node]=true;
    for(int a:graph[node]){
        if(!visited[a]){
            dfs(a);
        }
    }
    path.push_back(node);
}
void dfs2(int node){
    comp_no[node]=component.size();
    visited[node]=true;
    for(int a:rev_graph[node]){
        if(!visited[a]){
            dfs2(a);
        }
    }
}
ll Dp(int i){
    if(dp[i])return dp[i];
    dp[i]=group[i];
    for(int a:reverse_graph[i]){
        dp[i]=max(dp[i],Dp(a)+group[i]);
    }
    return dp[i];
}
int main(){
    int n,m;
    cin>>n>>m;
    coin.resize(n);
    graph.resize(n);
    visited.resize(n,false);
    comp_no.resize(n);
    rev_graph.resize(n);
    // reverse_graph.resize(n);
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(path.begin(),path.end());
    visited.assign(n,false);
    for(int i=0;i<path.size();i++){
        if(!visited[path[i]]){
            comp.clear();
            dfs2(path[i]);
            component.push_back(comp);
        }
    }
    group.resize(component.size());
    reverse_graph.resize(component.size());
    for(int i=0;i<n;i++){
        group[comp_no[i]]+=coin[i];
    }
    for(int i=0;i<n;i++){
        for(int j:graph[i]){
            if(comp_no[i]==comp_no[j])continue;
            reverse_graph[comp_no[j]].push_back(comp_no[i]);
        }
    }
    ll ans=0;
    
    for(int a:comp_no){
        ans=max(ans,Dp(a));
    }
    cout<<ans<<endl;

    
}