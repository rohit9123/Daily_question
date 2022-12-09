
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
vector<int> kmp(const string& s){
    int n=s.size();
    vector<int> pi(n);
    pi[0]=0;
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j])j++;
        pi[i]=j;
    }
    // cout<<"ok"<<endl;
    return pi;
}
void solve(){
    string s,pattern;
    cin>>s;
    cin>>pattern;
    // cout<<s<<pattern<<endl;
    vector<int> pi_pat=kmp(pattern);
    vector<int> ans;
    // bool found=false;
    int i=0,j=0,n=s.size(),m=pattern.size();
    while(i<n){
        //  cout<<i<<endl;
        if(pattern[j]==s[i]){
            i++;
            j++;
        }
        if(j==m){
            ans.push_back(i-m);
            j=pi_pat[j-1];
        }else if(i<n&&pattern[j]!=s[i]){
            if(j==0){
                i++;
            }else{
                j=pi_pat[j-1];
            }
        }
       
    }
    if(ans.size()){
        cout<<ans.size()<<endl;
        for(int a:ans){
            cout<<a+1<<" ";
        }
    }else{
        cout<<"Not Found"<<'\n';
    }
    cout<<'\n'<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}