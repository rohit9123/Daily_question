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
    vector<int> arr(n+2);
    
    // long long sum=0;
    for(int i=0;i<n+2;i++){
        cin>>arr[i];
        // sum+=arr[i];
    }
    sort(arr.begin(),arr.end());
    long long sum=0;
    unordered_set<long> ok;
    for(int i=0;i<n;i++){
        ok.insert(arr[i]);
        sum=sum+arr[i];
    }
    
    if(sum>arr[n+1]){
        cout<<-1<<endl;
    }
    else if(arr[n]==sum||arr[n+1]==sum){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }else{
        sum+=arr[n];
        long diff=sum-arr[n+1];
        if(ok.find(diff)!=ok.end()){
            int count=1;
            for(int i=0;i<=n;i++){
                if(arr[i]==diff&&count){
                    count--;
                }else{
                    cout<<arr[i]<<" ";
                }
            }
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }
    }


}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}