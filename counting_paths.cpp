//Link->https://cses.fi/problemset/task/1136/
//Author: Rohit Kumar
//Status: Accepted
//Time_complexity: O(nlongn)
//Space_complexity: O(n)
//Submission_date: 21/08/2022
//prequisite->binary lifting and prefix sum
//Question-> we have to find how much time a node is visited after all travel
//so the idea is simple whenever we go from a to b we have to travel through a to lca and b to lca
//we can find lca of a and b using binary lifting in log(n) time
//then we simply add +1 to a and b count and -1 to lca,and its parent
//because if we sum then lca will get sum of 2 but lca visited one time only so we put -1
// and then 1 is going to up to lca so cancel it we simply add -1 to lca parent


#include<iostream>
#include<vector>
using namespace std;
vector<vector<int > > graph; 
vector<vector<int> > binary_lifting;

vector<int> depth;

void binary_lift(int node,int parent,int dep){
    depth[node]=dep;
    if(parent!=-1){
        binary_lifting[node][0]=parent;
    }
    for(int i=1;i<19;i++){
        int parent=binary_lifting[node][i-1];
        if(parent==-1){
            break;
        }
        binary_lifting[node][i]=binary_lifting[parent][i-1];
    }
    for(int a:graph[node]){
        if(a!=parent){
            binary_lift(a,node,dep+1);
        }
    }
}
void accum(int node,vector<int>&count,int parent){
    for(int a:graph[node]){
        if(a!=parent){
            accum(a,count,node);
            count[node]+=count[a];
        }
    }
    // cout<<node<<" "<<count[node]<<endl;
}
void lca(int u,int v,vector<int>&count){
        count[u]++,count[v]++;
        if(depth[u]<depth[v])swap(u,v);
        int diff=depth[u]-depth[v];
        for(int i=0;i<=18;i++){
            if((1<<i)&diff){
                u=binary_lifting[u][i];
            }
        }
        if(u==v){
            count[u]--;
            if(binary_lifting[u][0]!=-1){
                count[binary_lifting[u][0]]--;
            }
        }
        else{
            for(int i=18;i>=0;i--){
                if(binary_lifting[u][i]!=binary_lifting[v][i]){
                    u=binary_lifting[u][i];
                    v=binary_lifting[v][i];
                }
            }
            if(binary_lifting[u][0]!=-1){
                
                count[binary_lifting[u][0]]--;
                int node=binary_lifting[u][0];
                if(binary_lifting[node][0]!=-1){
                    count[binary_lifting[node][0]]--;
                }
            }
        }
}
int main(){
    int n,q;
    cin>>n>>q;
    graph.resize(n+1);
    binary_lifting.resize(n+1,vector<int>(19,-1));
    depth.resize(n+1,-1);
    vector<int> count(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    binary_lift(1,-1,0);
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        lca(u,v,count);
        
    }
  
    accum(1,count,-1);
    for(int i=1;i<=n;i++){
        cout<<count[i]<<" ";
    }
}