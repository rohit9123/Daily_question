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
vector<vector<int> > graph;
vector<vector<int> > reverse_graph;
vector<int> path,component;
vector<int> visited;
vector<vector<int> > comp;
void dfs(int node){
    visited[node]=true;
    for(int a:graph[node]){
        if(visited[a]==false){
            dfs(a);
        }
    }
    path.push_back(node);
}
void dfs2(int node){
    visited[node]=true;
    component.push_back(node);
    for(int a:reverse_graph[node]){
        if(!visited[a]){
            dfs2(a);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n);
    reverse_graph.resize(n);
    visited.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            dfs(i);
        }
    }
    visited.assign(n,false);
    reverse(path.begin(),path.end());
    for(int a:path){
        if(visited[a]==false){
            component.clear();
            dfs2(a);
            comp.push_back(component);
        }
    }
    vector<int> part(n);
    for(int i=0;i<comp.size();i++){
        for(int a:comp[i]){
            part[a]=i+1;
        }
    }
    cout<<comp.size()<<endl;
    for(int i=0;i<n;i++){
        cout<<part[i]<<" ";
    }
}