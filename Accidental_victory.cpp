
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
        arr[i].second=i;
    }
    sort(arr.begin(),arr.end());
    vector<lli> prefix(n,0);
    prefix[0]=arr[0].first;
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i].first;
    }
    vector<int> ans;

    ans.push_back(arr.back().second+1);
    for(int i=n-2;i>=0;i--){
        if(prefix[i]>=arr[i+1].first){
            ans.push_back(arr[i].second+1);
        }else{
            break;
        }
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(int a:ans){
        cout<<a<<" ";

    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}