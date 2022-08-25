#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int t=0;//time is used to flatten the tree
vector<vector<int > > tree;
vector<int> value;
vector<int> arr;
unordered_map<int,int> start_time,finish_time;
vector<long long int> seg_tree;

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

int main(){
    int n,m;
    cin>>n>>m;
    tree.resize(n+1);
    value.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,0);
    seg_tree.resize(8*n);
    build_tree(0,n-1,0);
}