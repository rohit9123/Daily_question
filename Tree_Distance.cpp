#include<iostream>
#include<vector>
using namespace std;

void calculate_distance(int node,vector<vector<int> >&tree,vector<int>&distance,int parent,vector<int>&par,vector<int>& count_node){
    distance[node]=0;
    count_node[node]=1;
    par[node]=parent;
    for(int child:tree[node]){
        if(child!=parent){
            calculate_distance(child,tree,distance,node,par,count_node);
            distance[node]+=count_node[child]+distance[child];
            count_node[node]+=count_node[child];
        }
    }
    
}
void calculate_for_all(int node,vector<vector<int> >&tree,vector<int>&distance,int parent,vector<int>&par,vector<int>&count_node){
    if(parent!=-1){
        distance[node]=distance[node]+((distance[parent]-distance[node]-count_node[node])+count_node[parent]-count_node[node]);
        count_node[node]+=count_node[parent]-count_node[node];
    }
    for(int child:tree[node]){
        if(child!=parent){
            calculate_for_all(child,tree,distance,node,par,count_node);
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int> > tree(n+1);
    vector<int> distance(n+1,0);
    vector<int> parent(n+1,-1);
    vector<int> node(n+1,0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    calculate_distance(1,tree,distance,-1,parent,node);
    // for(int i=1;i<=n;i++){
    //     cout<<distance[i]<<" ";
    // }
    calculate_for_all(1,tree,distance,-1,parent,node);
    for(int i=1;i<=n;i++){
        cout<<distance[i]<<" ";
    }
    return 0;
}