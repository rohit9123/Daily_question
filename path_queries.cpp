#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<long long int> start_time,finish_time,arr,value,seg_tree;
int t=0;

void flatten(vector<vector<int> >&tree,int node,int parent){
    start_time[node]=t;
    arr.push_back(value[node]);
    t++;
    for(int a:tree[node]){
        if(a!=parent){
            flatten(tree,a,node);
        }
    }
    arr.push_back(-value[node]);
    finish_time[node]=t++;
}
void build_tree(int l,int r,int index){
    if(l==r){
        // cout<<arr[l]<<endl;
        seg_tree[index]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build_tree(l,mid,2*index+1);
    build_tree(mid+1,r,2*index+2);
    seg_tree[index]=seg_tree[2*index+1]+seg_tree[2*index+2];
}
void update(int index,int l,int r,int i,int value){
    if(index>r||index<l){
        return;
    }
    if(l==r&&l==index){
        seg_tree[i]=value;
        return ;
    }
    
    int mid=(l+r)/2;
    update(index,l,mid,2*i+1,value);
    update(index,mid+1,r,2*i+2,value);
    seg_tree[i]=seg_tree[2*i+1]+seg_tree[2*i+2];
}

long long int find_sum(int l,int r,int ql,int qr,int index){
    if(ql<=l&&qr>=r){
        // cout<<seg_tree[index]<<endl;
        return seg_tree[index];
    }
    if(qr<l||ql>r){
        return 0;
    }
    int mid=(l+r)/2;
    return find_sum(l,mid,ql,qr,2*index+1)+find_sum(mid+1,r,ql,qr,2*index+2);
}

int main(){
    int n,m;
    cin>>n>>m;
    start_time.resize(n+1);
    finish_time.resize(n+1);
    value.resize(n+1);
    seg_tree.resize(8*n,0);
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }
    vector<vector<int> > tree(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    flatten(tree,1,-1);
    build_tree(0,2*n-1,0);
    
    // cout<<endl;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        if(a==1){
            int node,value;
            cin>>node>>value;
            int index=start_time[node];
            update(index,0,2*n-1,0,value);  
            index=finish_time[node];
            update(index,0,2*n-1,0,-value);
        }else{
            int s;
            cin>>s;
            int index=start_time[s];
            // cout<<index<<endl;
            cout<<find_sum(0,2*n-1,0,index,0)<<endl;
        }
    }
}