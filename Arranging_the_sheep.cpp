
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
    vector<char>ok(n);
    for(int i=0;i<n;i++){
        cin>>ok[i];
    }
    vector<int> arr;
    for(int i=0;i<n;i++){
        if(ok[i]=='*'){
            arr.push_back(i);
        }
    }
    lli ans=0;
    n=arr.size();
    if(arr.size()==0){
        cout<<0<<endl;
        return;
    }
    int pos=arr[n/2]-1;
    for(int i=n/2-1;i>=0;i--){
        ans+=(pos-arr[i]);
        pos--;
    }
    pos=arr[n/2]+1;
    for(int i=n/2+1;i<n;i++){
        ans+=(arr[i]-pos);
        pos++;
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