// Question Link: https://codeforces.com/problemset/problem/1717/C
// Question Name: Madoka and Formal Statement
// Question Category: Greedy  tag
// Question Difficulty: 1300
//we have to simply see weather we can build this array to b or not
//so the approach was simple we have to just check if this element is in range  <=arr[i+1]+1 if it is then we can build it else we can't
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
#define f first
#define s second
#define mod 1000000007
#define pb push_back
#define in insert
#define pres(c,x) ((c).find(x)!=c.end());
#define lli long long int
#define vl vector<ll>
 
 
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
using namespace std;

void solve();

int main(){
    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
}

void solve(){
   int n;
   cin>>n;
   vector<int> arr(n+1),brr(n+1);
   for(int i=0;i<n;i++){
         cin>>arr[i];
   }
    for(int i=0;i<n;i++){
            cin>>brr[i];
    }

    for(int i=0;i<n;i++){
        if(arr[i]>brr[i]){
            cout<<"NO"<<endl;
            return;
        }
    }

    if(brr[0]+1<brr[n-1])
    {
        if(arr[n-1]!=brr[n-1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(arr[i]==brr[i]){
            continue;
        }else if(brr[i]>brr[i+1]+1){
            cout<<"NO"<<endl;
            return;
        }

    }
    
    cout<<"YES"<<endl;
}