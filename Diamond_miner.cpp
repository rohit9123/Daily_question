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
    int n,m;
    cin>>n>>m;
    vector<int> rem(m+1);
    for(int i=0;i<n;i++){
        long a;
        cin>>a;
        rem[a%m]++;
    }
    int ans=rem[0]==0?0:1;
    
    for(int i=1;i<m;i++){
        if(rem[i]>0){
            int mini=min(rem[i],rem[m-i]);
            int maxi=max(rem[i],rem[m-i]);
            if(maxi==mini){
                ans+=1;
            }else
            ans+=maxi-mini;
            rem[i]=rem[m-i]=0;
            // cout<<ans<<" "<<i<<endl;
        }
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