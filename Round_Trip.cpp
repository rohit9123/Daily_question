//Question Link->https://cses.fi/problemset/task/1669/
//Name->Message Route
//Author->Rohit Kumar
//Status->Accepted
//problem-> in this we have to find a circle in directed graph of size 2 or greater than 2
//so we simply use dfs and if we find a node which is already visited then we have found a circle
//we used a vector to store the parent of each node and we check if the parent of the node is not the node which is currently being visited
//then we have found a circle
#include <bits/stdc++.h>

using namespace std;
vector<int> parent(100001,-1);
vector<int> ans;
int sp,ep;
bool  dfs(vector<vector<int> >&graph,int node,vector<int>&visit,int time,int par=-1){
    visit[node]=time++;
    parent[node]=par;
    for(int a:graph[node]){
        if(a==par)continue;
        if(visit[a]==-1){
            bool ans=dfs(graph,a,visit,time+1,node);
            if(ans)return true;
        }else{
            int time=visit[a]-visit[node];
            if(time>=2){
                ans.push_back(node);
                ans.push_back(a);
                while(parent[a]!=node){
                    ans.push_back(parent[a]);
                    a=parent[a];
                }
                ans.push_back(node);
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
   
    vector<int> visit(n+1,-1);
    for(int i=1;i<=n;i++){
        
        if(visit[i]==-1){
           
            bool answer=dfs(graph,i,visit,0);
            if(answer){
                cout<<ans.size()<<endl;
                for(int a:ans){
                    cout<<a<<" ";
                }
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}