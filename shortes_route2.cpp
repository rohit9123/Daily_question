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
//floyd warshall
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long> > graph(n+1,vector<long long>(n+1,1e17));
    for(int i=0;i<m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        graph[u][v]=min(w,graph[u][v]);
        graph[v][u]=min(w,graph[v][u]);
        
    }
    for(int i=1;i<=n;i++){
        graph[i][i]=0;
    }
    for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (graph[i][k] < 1e17 && graph[k][j] < 1e17)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]); 
        }
    }
}
    
    while(q--){
        int u,v;
        cin>>u>>v;
        if(graph[u][v]==1e17)cout<<-1<<endl;
        else cout<<graph[u][v]<<endl;
        
    }
}