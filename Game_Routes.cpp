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
int n,m;
vector<vector<int> > graph;
vector<int> visited;
vector<long long> dp;
// int mod=1e9+7;
long long dfs(int src,int dest){
    if(src==dest){
        return 1;
    }
    long long ans=0;
    visited[src]=1;
    for(auto x:graph[src]){
        if(!visited[x]){
            ans+=dfs(x,dest);
            ans%=mod;
        }else{
            ans+=dp[x];
            ans%=mod;
        }
        
    }
    return dp[src]=ans%mod;
}
int main(){
    fast;
    cin>>n>>m;
    graph.resize(n+1);
    visited.resize(n+1,0);
    dp.resize(n+1,0);
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
    }
    dfs(1,n);
    cout<<dp[1]<<endl;
    return 0;
}