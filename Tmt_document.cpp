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
    string s;
    cin>>s;
    vector<int> left(n,0),right(n,0);
    int total_t=0,total_m=0;
    total_t=left[0]=s[0]=='T'?1:0;
    right[n-1]=s[n-1]=='T'?1:0;
    
    for(int i=1;i<n;i++){
        if(s[i]=='T'){
            total_t++;
            left[i]=left[i-1]+1;
        }else{
            left[i]=left[i-1];
            total_m++;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(s[i]=='T'){
            right[i]=right[i+1]+1;
        }else{
            right[i]=right[i+1];
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]=='M'){
            if(count+1>left[i]){
                cout<<"NO"<<endl;
                return;
            }
            count++;
        }
    }
    count=0;
    // cout<<'o';
    for(int i=n-1;i>=0;i--){
        if(s[i]=='M'){
            if(count+1>right[i]){
                // cout<<i<<endl;
                cout<<"NO"<<endl;
                return;
            }
            count++;
        }
    }
    // cout<<'o';
    // cout<<total_m<<" "<<total_t<<endl;
    if(total_m*2==total_t){
        // cout<<"Ok"<<endl;
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}
int main(){
    fast;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}