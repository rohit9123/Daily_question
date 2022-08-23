//link->https://cses.fi/problemset/task/1137/
//this solution is combination of eulers tour and segment tree
//so we want to find sum of subtree of a node
//so first we flatten tree with the help of euler tour
//then we store the entering time and exit number
//and then we use segment tree to find sum of subtree of a node or update for node

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int t=0;
vector<vector<int > > tree;
vector<int> value;
vector<int> arr;
unordered_map<int,int> start_time,finish_time;
vector<long long int> seg_tree,visited;

void dfs(int node,int parent){
    start_time[node]=t++;
    arr.push_back(value[node]);
    for(int a:tree[node]){
        if(a!=parent){
            dfs(a,node);
        }
    }
    finish_time[node]=t++;
    arr.push_back(value[node]);
}
void build_tree(int l,int r,int index){
    if(l==r){
        // int no=arr[l];

        seg_tree[index]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build_tree(l,mid,2*index+1);
    build_tree(mid+1,r,2*index+2);
    seg_tree[index]=seg_tree[2*index+1]+seg_tree[2*index+2];
}
void update(int point,int l,int r,int index,int value){
    if(point>r||point<l){
        return;
    }
    if(l==r&&l==point){
        seg_tree[index]=value;
        return ;
    }
    
    int mid=(l+r)/2;
    update(point,l,mid,2*index+1,value);
    update(point,mid+1,r,2*index+2,value);
    seg_tree[index]=seg_tree[2*index+1]+seg_tree[2*index+2];
}

long long findans(int ql,int qr,int l,int r,int index){
    if(ql<=l&&qr>=r){
        return seg_tree[index];
    }
    if(ql>r||qr<l){
        return 0;
    }
    int mid=(l+r)/2;
    return findans(ql,qr,l,mid,2*index+1)+findans(ql,qr,mid+1,r,2*index+2);
}
int main(){
    int n,m;
    cin>>n>>m;
    tree.resize(n+1);
    value.resize(n+1);
    visited.resize(n+1,0);
    seg_tree.resize(8*n+10);
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,-1);
    // cout<<arr.size()<<endl;
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    build_tree(0,2*n-1,0);
    // for(int i=0;i<20;i++){
    //     cout<<seg_tree[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<m;i++){
        int type;
        cin>>type;
        if(type==1){
            int node,value;
            cin>>node>>value;
            update(start_time[node],0,2*n-1,0,value);
            update(finish_time[node],0,2*n-1,0,value);
        }else{
            int node;
            cin>>node;
            int start=start_time[node];
            int end=finish_time[node];
            // cout<<start<<" "<<end<<endl;
            long long int ans=findans(start,end,0,2*n-1,0);
            cout<<ans/2<<endl;
        }
    }
}