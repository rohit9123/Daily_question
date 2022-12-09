
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

int findans(vector<int>&pos,vector<int>& sp){
    int ans=0;
    int m=sp.size(),n=pos.size();
    int suffix[n];
    map<int,int> ok;
    vector<int> same;
    for(int a:pos){
        ok[a]++;
    }
    for(int a:sp){
        ok[a]++;
    }
    for(auto it=ok.begin();it!=ok.end();it++){
        if(it->second==2){
            same.push_back(it->first);
        }
    }
    for(int i=0;i<m;i++){
        // cout<<i<<endl;
        int last_pos=sp[i];
        if(pos[0]>last_pos){
            continue;
        }
        int l=0,r=pos.size()-1,ans1;
        while(l<=r){
            int mid=(l+r)/2;
            if(pos[mid]<=last_pos){
                ans1=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        int count=ans+1;
        int minus=last_pos-ans1-1;
        l=0,r=m-1;
        
        int ans2;
        while(l<=r){
            int mid=(l+r)/2;
            if(sp[mid]>=minus){
                ans2=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        int answer=0;
        
        ans=max(ans,i-ans2+1+(answer));
        // cout<<ans<<endl;

    }
    return ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> neg,pos,neg_pos,pos_pos;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a<0){
            neg.push_back(-1*a);
        }else{
            neg.push_back(a);
        }
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        if(a<0){
            neg_pos.push_back(-1*a);
        }else{
            neg_pos.push_back(a);
        }
    }
    int ans=findans(neg,neg_pos);
    // cout<<ans<<endl;
    ans+=findans(pos,pos_pos);
    cout<<ans<<endl;


}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
