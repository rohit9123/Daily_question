//link->https://cses.fi/problemset/task/1133/
// Time: O(N) beacuse we processing a node only 2 times
// Space: O(N)
//parent vector is of no use 
//the concept here is use the parent node to find distance to all node
// the formula is easy for any child to calculate to all distance
// is distance[child]=distance[child]+(distance[parent]-distance[child]-count_node[child])+(count_node[parent]-count_child[child])
// let p1=distance[child]
//let p2=distance[parent]-distance[child]-count_node[child]
//p2 is how much node inculding the parent and parnet is connected to the parent apart from child
//let p3=count_node[parent]-count_child[child]
//p3 is used to add the distance of the child to the parent
//the formula is p1+p2+p3

#include<bits/stdc++.h>
#define long long long int
using namespace std;

void calculate_distance(int node,vector<vector<long> >&tree,vector<long>&distance,int parent,vector<long>&par,vector<long>& count_node){
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
void calculate_for_all(long node,vector<vector<long> >&tree,vector<long>&distance,long parent,vector<long>&par,vector<long>&count_node){
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
    vector<vector<long> > tree(n+1);
    vector<long> distance(n+1,0);
    vector<long> parent(n+1,-1);
    vector<long> node(n+1,0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    calculate_distance(1,tree,distance,-1,parent,node);
    calculate_for_all(1,tree,distance,-1,parent,node);
    for(int i=1;i<=n;i++){
        cout<<distance[i]<<" ";
    }
    return 0;
}