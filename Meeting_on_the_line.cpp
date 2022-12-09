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
    int n;
    cin>>n;
    vector<pair<int,int> > arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].second;
    }
    sort(arr.begin(),arr.end());
    double l=0,r=1e9,ans;
    while(r-l>=0.0000000005){
        double mid=(l+r)/2;
        double maxi=0,mini=1e9;
        for(int i=0;i<n;i++){
            if(arr[i].second>mid){
                maxi=1e9;
                mini=0;
                break;
            }else{
                maxi=max(maxi,arr[i].first-(mid-arr[i].second));
                mini=min(mini,arr[i].first+(mid-arr[i].second));
            }
        }
        if(maxi<=mini){
            r=mid;
            ans=maxi;
        }else{
            l=mid;
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