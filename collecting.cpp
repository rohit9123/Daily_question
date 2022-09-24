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
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
     map<int,int> ok;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ok[arr[i]]=i;
    }
    int last=-1,ans=1;
    for(int i=1;i<=n;i++){
        if(ok[i]<last){
            last=ok[i];
            ans++;
        }else{
            last=ok[i];
        }
    }
    cout<<ans<<endl;
   
}