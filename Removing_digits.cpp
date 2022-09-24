
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
int dp[1000001];
int findans(int n){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int no=n;
    int ans=1e9;
    while(no){
        int last=no%10;
        if(last!=0){
            ans=min(ans,1+findans(n-last));

        }
        no=no/10;
    }
    return dp[n]=ans;

}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    int ans=findans(n);
    cout<<ans<<endl;
}