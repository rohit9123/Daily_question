#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > tree;
vector<int> start_time,finish_time,arr,value,seg_tree;

int t=0;
void flatten(int node,int parent){
    start_time[node]=t;
    arr.push_back(value[node]);
    t++;
    for(int a:tree[node]){
        if(a!=parent){
            flatten(a,node);
        }
    }
    arr.push_back(-value[node]);
    finish_time[node]=t++;
}
void build_tree(int l,int r,int index){
    if(l==r){
        seg_tree[index]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build_tree(l,mid,2*index+1);
    build_tree(mid+1,r,2*index+2);
    seg_tree[index]=max(seg_tree[2*index+1],seg_tree[2*index+2]);
}
int main(){
    int n,m;
    cin>>n>>m;
    tree.resize(n+1);
    start_time.resize(n+1);
    finish_time.resize(n+1);
    arr.resize(n+1);
    value.resize(n+1);
    seg_tree.resize(8*n+1);
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    flatten(1,-1);
    build_tree(0,2*n-1,0);
}