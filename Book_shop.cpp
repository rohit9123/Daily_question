
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
int findans(int index,int n,int left_price,vector<int>&price,vector<int>&page,vector<vector<int> >&dp){
    if(index==n){
        return 0;
    }
    if(dp[index][left_price]!=-1){
        return dp[index][left_price];
    }
    int ans=0;
    if(left_price>=price[index]){
        ans=page[index]+findans(index+1,n,left_price-price[index],price,page,dp);
    }
    ans=max(ans,findans(index+1,n,left_price,price,page,dp));
    return dp[index][left_price]=ans;
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> price(n), pages(n);
  for (int&v : price) cin >> v;
  for (int&v : pages) cin >> v;
  vector<vector<int>> dp(n+1,vector<int>(x+1,0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-price[i-1];
      if (left >= 0) {
	dp[i][j] = max(dp[i][j], dp[i-1][left]+pages[i-1]);
      }
    }
  }
  cout << dp[n][x] << endl;
    return 0;
}