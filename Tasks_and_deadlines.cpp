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
static bool mysrt(pair<int,int>&a,pair<int,int>&b){
   return a.first<b.first;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > ok(n);
    for(int i=0;i<n;i++){
        cin>>ok[i].first>>ok[i].second;
    }
    sort(ok.begin(),ok.end(),mysrt);
    ll ans=0;
    ll time=0;
    for(int i=0;i<n;i++){
        // cout<<ok[i].first<<" "<<ok[i].second<<endl;
        time+=ok[i].first;
        ans+=ok[i].second-(time);
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
}