
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
vector<int> leaf;
vector<vector<int> > arr;
void dfs(int node){
    for(int a:arr[node]){
        if(arr[a].size()==0){
            leaf[node]++;
        }else{
            dfs(a);
        }
    }
}
int main(){
    int n;
    cin>>n;
    arr.resize(n+1);
    leaf.resize(n+1,0);
    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        arr[a].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        // cout<<leaf[i]<<endl;/
        if(leaf[i]>0&&leaf[i]<3){
            cout<<"NO"<<endl;
            return 0;
        }else if(arr[i].size()>0&&leaf[i]==0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}