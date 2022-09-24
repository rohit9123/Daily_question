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
bool mycomp(pair<int,int> a,pair<int,int> b){
    if(a.ss==b.ss){
        return a.fs<b.fs;
    }
    return a.fs<b.ss;

}
int main(){
    int m;
    cin>>m;
    priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    int ans=0,maxi=0;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        pq.push(mp(a,1));
        pq.push(mp(b,-1));
    }
    while(!pq.empty()){
        pair<int,int> p=pq.top();
        pq.pop();
        ans+=p.ss;
        maxi=max(maxi,ans);
    }
    cout<<maxi<<endl;


}