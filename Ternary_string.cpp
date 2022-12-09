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
void solve(){
    string s;
    cin>>s;
    vector<ll> one,two,three;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            one.push_back(i);
        }else if(s[i]=='2'){
            two.push_back(i);
        }else{
            three.push_back(i);
        }
    }
    one.push_back(1e18);
    two.push_back(1e18);
    three.push_back(1e18);
    ll ans=1e18;
    for(int i=0;i<s.size();i++){
        ll a=*lower_bound(one.begin(),one.end(),i);
        ll b=*lower_bound(two.begin(),two.end(),i);
        ll c=*lower_bound(three.begin(),three.end(),i);
        ll maxi=max(a,max(b,c));
        ll mini=min(a,min(b,c));
        // cout<<maxi-mini<<endl;
        // cout<<maxi<<" "<<mini<<endl;
        ans=min(ans,maxi-mini+1);

    }
    if(ans>s.size()){
        cout<<0<<endl;
    }else{
        cout<<ans<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}