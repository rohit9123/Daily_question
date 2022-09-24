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
using namespace std;
struct edge{
    int u,v,w;
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<edge> edges(m);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i].u=u;
        edges[i].v=v;
        edges[i].w=w;
    }
    vector<long> dist(n+1,1e14);
    vector<int> parent(n+1,-1);
    dist[edges[0].u]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            int u=edges[j].u;
            int v=edges[j].v;
            int w=edges[j].w;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                parent[v]=u;
            }
        }
    }
    bool ok=false;
    int c=-1;
    for(int i=0;i<m;i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;
        if(dist[u]+w<dist[v]){
            ok=true;
            c=v;
            break;
        }
    }
    
    if(!ok){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<=n;i++){
            c=parent[c];
        }
        vector<int> cycle;
        for(int i=c;;i=parent[i]){
            cycle.pb(i);
            if(i==c&&cycle.size()>1){
                break;
            }
        }
        reverse(cycle.begin(),cycle.end());
        for(auto x:cycle){
            cout<<x<<" ";
        }

    }
    
}

int countBoxes(string digits,vector<string> password){
    vector<int> arr(10,0);
    for(int i=0;i<digits.size();i++){
        arr[digits[i]-'0']++;
    }
    int ans=0;
    for(int i=0;i<password;i++){
        vector<int> temp(10,0);
        for(int j=0;j<password[i].size();j++){
            temp[password[i][j]-'0']++;
        }
        bool ok=true;
        for(int j=0;j<10;j++){
            if(temp[j]>arr[j]){
                ok=false;
                break;
            }
        }
        if(ok){
            ans++;
        }
    }
    return ans;
}
int answer=0;
void calculate(vector<vector<int> >&adj,int node,vector<int>&value,vector<int>&ans){
    if(adj[node].size()==0){
        ans[node]=value[node];
        return;
    }
    vector<int> node_value;
    
    for(int i=0;i<adj[node].size();i++){
        calculate(adj,adj[node][i],value,ans);
        node_value.push_back(ans[adj[node][i]]);
    }
    // vector<int> ank(32,0);
    int par=node_value.size();
    vector<vector<int> > adk(par,vector<int>(32,0));
    
    for(int i=0;i<node_value.size();i++){
        for(int j=0;j<32;j++){
            if(node_value[i]&(1<<j)){
                adk[i][j]++;
                // ank[j]++; 
            }
        }
    }
    for(int i=0;i<node_value.size();i++){
        int nodes=node_value[i];
        int pope=ans[node];
        for(int j=0;j<node_value.size();j++){
            if(i==j){
                continue;
            }
            pope&=ans[j];
        }
        if(pope==nodes){
            answer++;
        }
    }
    int values=node_value[node];
    for(int a:adj[node]){
        values=values&node_value[a];
    }
    ans[node]=values;
    
}

int getNumways(int g_nodes,vector<int> g_form,vector<int> g_to,vector<int>&value){
    vector<vector<int> > adj(g_nodes);
    int parent=-1;
    for(int i=0;i<g_form.size();i++){
        if(g_form[i]==g_to[i]){
            parent=g_form[i];
            continue;
        }
        adj[g_form[i]].pb(g_to[i]);
        
    }
    return answer;

    

}