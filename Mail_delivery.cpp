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
#define maxn 200005
 
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
using namespace std;

int degree[maxn];
int visited[maxn];
vector<vector<int> > graph;
bool checking(){
    int odd=0;
    for(int i=0;i<maxn;i++){
        if(degree[i]&1){
            odd++;
        }
    }
    if(odd==0||odd==2){
        return true;
    }
    return false;
}
void dfs(int node){
    visited[node]=true;
    for(int a:graph[node]){
        if(!visited[a]){
            dfs(a);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            count++;
        }
    }

    bool check=checking();
    if(!check||count>1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    


}