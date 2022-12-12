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
bool mysrt(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
vector<int> parent;
int find_parent(int node){
    if(parent[node]==node){
        return node;
    }
    return  parent[node]=find_parent(parent[node]);
}
int main(){
    int n,m;
    vector<vector<int> >arr;
    
    cin>>n>>m;
    parent.resize(n);
    for(int i=0;i<m;i++){
        vector<int> p(3);
        cin>>p[0]>>p[1]>>p[2];
        p[0]--;p[1]--;
        arr.push_back(p);
    }
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    sort(arr.begin(),arr.end(),mysrt);
    long long ans=0;
    int road=0;
    int i=0;
    while(road<n-1&&i<m){
        int par=find_parent(arr[i][0]);
        int par2=find_parent(arr[i][1]);
        int cost=arr[i][2];
        i++;
        if(par!=par2){
            parent[par2]=par;
            road++;
            ans+=cost;
        }
    }
    if(road==n-1)cout<<ans<<endl;
    else
    cout<<"IMPOSSIBLE"<<endl;
    return 0;

}