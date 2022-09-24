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
    fast;
    int n,m;
    cin>>n>>m;
    multiset<int> arr;
    rep(i,0,n){
        int x;
        cin>>x;
        arr.in(-1*x);
    }
    for(int j=0;j<m;j++){
        int x;
        cin>>x;
        auto it=arr.lower_bound(-1*x);
        if(it==arr.end()){
            cout<<-1<<endl;
        }else{
            cout<<-1*(*it)<<endl;
            arr.erase(it);
        }
    }

    
}