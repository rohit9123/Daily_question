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
int main(){
    cin>>n>>m;
    vector<vector<int> > graph(n+1);
    vector<int> indegree(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        indegree[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.push_back(u);
        for(int i=0;i<graph[u].size();i++){
            indegree[graph[u][i]]--;
            if(indegree[graph[u][i]]==0){
                q.push(graph[u][i]);
            }
        }
    }
    for(int i=0;i<=n;i++){
        if(indegree[i]!=0){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
}