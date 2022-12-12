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
vector<pair<int,int> > parent;
pair<int,int> find_parent(int node){
    if(parent[node].first==node){
        return parent[node];
    }
    return parent[node]=find_parent(parent[node].first);
}
int main(){
    int n,m;
    cin>>n>>m;
    parent.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=make_pair(i,1);
    }
    int component=n,biggest=1;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        pair<int,int> p1=find_parent(a);
        pair<int,int> p2=find_parent(b);
        if(p1.first!=p2.first){
            biggest=max(biggest,p1.second+p2.second);
            parent[p2.first].first=p1.first;
            parent[p1.first].second+=p2.second;
            component--;
        }
        cout<<component<<" "<<biggest<<endl;
    }
}