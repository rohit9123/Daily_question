
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
    int n,m,g;
    cin>>n>>m>>g;
    vector<int> arr(n);
    vector<int> prefix(n)
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    prefix[0]=arr[0]%g==0?1:0;
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+(arr[i]%g==0?1:0);
    }
    int l=0,r=n-1,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]<=m){
            ans=prefix[mid];
            l=mid+1;
        }else{
            r=mid-1;
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