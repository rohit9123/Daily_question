
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
    int x,n;
    cin>>x>>n;
    vector<int> arr(n),gaps(n);
    set<int> ok;
    ok.insert(0);
    ok.insert(x);
    for(int i=0;i<n;i++){
        // cout<<i<<endl;
        int point;
        cin>>point;
        ok.insert(point);
        gaps[i]=point;
    }
    vector<int> answer;
    int prev=0;
    int ans=0;
    for(int a:ok){
        // cout<<a<<endl;
        ans=max(ans,a-prev);
        prev=a;
    }
    // cout<<ans<<endl;
    // answer[n-1]=ans;
    answer.push_back(ans);
    for(int i=n-1;i>0;i--){
        int upper=ok.erase(gaps[i]);
        auto it=ok.upper_bound(gaps[i]);
        int high=*it;
        int low=*(--it);
        ans=max(ans,high-low);
        // answer[i-1]=ans;
        answer.push_back(ans);
    }
    reverse(answer.begin(),answer.end());
    for(int a:answer){
        cout<<a<<" ";
    }
}