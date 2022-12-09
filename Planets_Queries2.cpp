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
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    vector<vector<int> > parent(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]--;
        parent[arr[i]].push_back(i);
    }
    vector<int> cycle_id(n,-2);
    vector<map<int,int> > cycles;
    for(int i=0;i<n;i++){
        if(cycle_id[i]!=-2){
            continue;
        }
        vector<int> path{i};
        int at=i;
        while(cycle_id[arr[at]]==-2){
            at=arr[at];
            cycle_id[at]=-3;
            path.push_back(at);
        }
        map<int,int> cycle;
        bool in_cycle=false;
        for(int i:path){
            in_cycle=in_cycle||i==arr[at];
            if(in_cycle){
                cycle[i]=cycle.size();
            }
            cycle_id[i]=in_cycle?cycles.size():-1;
        }
        cycles.push_back(cycle);
    }
    vector<int> cyc_dist(n);
    for(int i=0;i<n;i++){
        if(cycle_id[arr[i]]==-1||cycle_id[i]!=-1){
            continue;
        }
        cyc_dist[i]=1;
        vector<int> stk(parent[i]);
        while(!stk.empty()){
            int curr=stk.back();
            stk.pop_back();
            cyc_dist[curr]=cyc_dist[arr[curr]]+1;
            stk.insert(stk.end(),parent[curr].begin(),parent[curr].end());
        }

    }
    int log2=std::ceil(std::log2(n));
    vector<vector<int> > binary_lifting(n,vector<int>(log2+1));
    for(int i=0;i<n;i++){
        binary_lifting[i][0]=arr[i];
    }
    for(int i=1;i<=log2;i++){
        for(int j=0;j<n;j++){
            binary_lifting[j][i]=binary_lifting[binary_lifting[j][i-1]][i-1];
        }
    }
    auto lift= [&] (int pos,int dist){
        for(int i=log2;i>=0;i--){
            if((dist&(1<<i))!=0){
                pos=binary_lifting[pos][i];
            }
        }
        return pos;
    };

    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        if(cycle_id[binary_lifting[u][log2]]!=cycle_id[binary_lifting[v][log2]]){
            cout<<-1<<endl;
            continue;
        }
        if(cycle_id[u]!=-1||cycle_id[v]!=-1){

            if(cycle_id[v]==-1&&cycle_id[u]!=-1){
                cout<<-1<<endl;
                continue;
            }
            int dist=cyc_dist[u];
            int node=lift(u,cyc_dist[u]);
            map<int,int>&cyc=cycles[cycle_id[node]];
            int u_index=cyc[node];
            int v_index=cyc[v];
            int diff=u_index<=v_index?v_index-u_index:cyc.size()-(u_index-v_index);
            cout<<dist+diff<<endl;
        }else{
            if(cyc_dist[v]>cyc_dist[u]){
                cout<<-1<<endl;
                continue;
            }
            int diff=cyc_dist[u]-cyc_dist[v];
            cout<<(lift(u,diff)==v?diff:-1)<<endl;
        }
    }
    return 0;
}