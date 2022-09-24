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

bool can_do(vector<lli>&arr,lli time,lli& n,lli& k){
    lli work=0;
    for(int i=0;i<n;i++){
        work+=(time/arr[i]);
    }
    if(work>=k){
        return true;
    }
    return false;
}

int main(){
    lli  n,k;
    cin>>n>>k;
    vector<lli> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    lli l=arr[0],r=arr[0]*k,ans=r;
    while(l<=r){
        lli mid=(l+r)/2;
        if(can_do(arr,mid,n,k)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}