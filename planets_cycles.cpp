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
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<vector<int> >before(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]--;
        before[arr[i]].push_back(i);
    }
    vector<int> cycle_id(n,-2);
    vector<map<int,int> > cycles;
    for(int i=0;i<n;i++){
        if(cycle_id[i]!=-2){
            continue;
        }
        vector<int> path;
        path.push_back(i);
        int at=i;
        while(cycle_id[arr[at]]==-2){
            at=arr[at];
            cycle_id[at]=-3;
            path.push_back(at);
        }
        bool is_cyc=false;
        map<int,int> cycle;
        for(int a:path){
            is_cyc=is_cyc||a==arr[at];
            if(is_cyc){
                cycle[a]=cycle.size();
            }
            cycle_id[a]=is_cyc?cycles.size():-1;
        }
        cycles.push_back(cycle);
    }
    vector<int>cyc_dist(n);
    vector<int>which_cycle(n);
    for(int i=0;i<n;i++){
        if(cycle_id[arr[i]]==-1||cycle_id[i]!=-1){
            continue;
        }
        vector<int> stack(before[i]);
        which_cycle[i]=cycle_id[arr[i]];
        cyc_dist[i]=1;
        while(stack.size()){
            int node=stack.back();
            stack.pop_back();
            cyc_dist[node]=cyc_dist[arr[node]]+1;
            which_cycle[node]=which_cycle[arr[node]];
            stack.insert(stack.end(),before[node].begin(),before[node].end());
        }

    }
    for(int i=0;i<n;i++){
        if(cycle_id[i]!=-1){
            cout<<cycles[cycle_id[i]].size()<<" ";
        }else{
            cout<<cyc_dist[i]+cycles[which_cycle[i]].size()<<" ";
        }
    }


}