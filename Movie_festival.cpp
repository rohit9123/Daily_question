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
bool mycomp(pair<int,int> a,pair<int,int> b){
    if(a.ss==b.ss){
        return a.fs<b.fs;
    }
    return a.ss<b.ss;
 
}
int main(){
    fast;
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > arr(n);
    rep(i,0,n){
        int a;
        cin>>a;
        arr[i]=mp(a,i+1);
    }
    sort(arr.begin(),arr.end());
    for(int i=0,j=n-1;i<j;){
        if(arr[i].fs+arr[j].fs==m){
            cout<<arr[i].ss<<" "<<arr[j].ss<<endl;
            return 0;
        }else if(arr[i].fs+arr[j].fs<m){
            i++;
        }else{
            j--;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;

 
}