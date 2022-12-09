
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
vector<int> input,seg_tree;
void build_tree(int start,int end,int index){
    if(start==end){
        seg_tree[index]=input[start];
        return;
    }
    int mid=(start+end)/2;
    build_tree(start,mid,2*index+1);
    build_tree(mid+1,end,2*index+2);
    seg_tree[index]=max(seg_tree[2*index+1],seg_tree[2*index+2]);
}
int find_index(int start,int end,int a,int index){
    if(start==end){
        return start;
    }
    int mid=(start+end)/2;
    if(seg_tree[2*index+1]>=a){
        return find_index(start,mid,a,2*index+1);
    }
    return find_index(mid+1,end,a,2*index+2);
}
void update(int start,int end,int a,int ind,int index){
    if(start==end&&start==ind){
        seg_tree[index]-=a;
        return;
    }
    int mid=(start+end)/2;
    if(mid>=ind){
        update(start,mid,a,ind,2*index+1);
    }else{
        update(mid+1,end,a,ind,2*index+2);
    }
    seg_tree[index]=max(seg_tree[2*index+1],seg_tree[2*index+2]);
}
int main(){
    int n,m;
    cin>>n>>m;
    input.resize(n);
    seg_tree.resize(4*n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    build_tree(0,n-1,0);
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        if(seg_tree[0]>=a){
            int index=find_index(0,n-1,a,0);
            cout<<index+1<<" ";
            update(0,n-1,a,index,0);
        }else{
            cout<<0<<" ";
        }
    }
    return 0;
}