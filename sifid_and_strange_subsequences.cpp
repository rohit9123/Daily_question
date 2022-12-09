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
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int ans=0,count=0;
    int first=1e9+7;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            first=min(arr[i],first);
        }else{
            ans++;
        }
    }
    int flag=first<1e9+7;
    for(int i=1;i<n;i++){
        if(arr[i]<=0){
            flag&=(arr[i]-arr[i-1]>=first);
        }
    }
    if(flag)
    cout<<ans+1<<endl;
    else
    cout<<(ans)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}