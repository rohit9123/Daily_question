
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
vector<int> ind,out,vis;

int n,e;
void dfs(int node){
    vis[node]=1;
    for(int a:graph[node]){
        out[node]=1;
        ind[node]=1;
        if(vis==0){
            dfs(a);
        }
    }
}
void solve(){
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int l=0,r=0;
    int ans=1;
    multiset<int> ok;
    ok.insert(arr[0]);
    for(int l=0,r=1;r<n;r++){
        int no=arr[i];
        int smallest=*(ok.begin());
        int largest=*(--ok.end());
        while(ok.size()&&(abs(no-largest)>1||abs(no-largest)>1)){
            ok.erase(ok.find(arr[l++]));
        }
        ok.insert(arr[r]);
        ans=max(ans,r-l-1);

    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}