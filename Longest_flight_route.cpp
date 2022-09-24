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
vector<vector<int> > graph,graph2;
vector<int> visited,deep,deep2,parent,parent2;
int dfs(int src,int dest){
    if(src==dest){
        deep[src]=1;
        return 1;
    }
    int ans=0;
    visited[src]=1;
    for(auto x:graph[src]){
        if(!visited[x]){
            ans=max(ans,dfs(x,dest));
        }else if(visited[x]==1){
            ans=max(ans,deep[x]);
        }
    }
    // cout<<src<<" "<<ans+1<<endl;
    if(ans!=0)
    return deep[src]=ans+1;
    else
    return deep[src]=0;
}
bool findpath(int src,int dest,vector<vector<int> >&graph){
    queue<int> q;
    q.push(src);
    visited[src]=1;
    int ans=0;
    while(!q.empty()){
        
        for(int i=q.size()-1;i>=0;i--){
            int node=q.front();
            q.pop();
            if(node==dest){
                return true;
            }
            for(auto it:graph[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
        ans++;
    }
    return false;
}

int main(){
    cin>>n>>m;
    graph.resize(n+1);
    visited.resize(n+1,0);
    deep.resize(n+1,0);
    
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        graph[a].pb(b);
        
    }
    bool can_visit=findpath(1,n,graph);
    if(!can_visit){
        cout<<"IMPOSSIBLE";
        return 0;
    }else{
        visited.assign(n+1,0);
        dfs(1,n);
        int ans=deep[1];
        cout<<ans<<endl;
        
        int node=1;
        cout<<node<<" ";
        while(node!=n&&ans>=1){
            for(auto x:graph[node]){
                if(deep[x]==ans-1){
                    node=x;
                    ans--;
                    break;
                }
            }

            cout<<node<<" ";
        }

    }
}