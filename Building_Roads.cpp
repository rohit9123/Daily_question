//Question Link->https://cses.fi/problemset/task/1666/
//Name->Building Roads
//Author->Rohit Kumar
//Status->Accepted
//Time_complexity->O(n)
//Space_complexity->O(n)
//idea-> so we have to connect all the road so we now in undirected graph we simply have to trieverse to count the connected component
//and the number of connected component-1 will be the number of road we have to build
//we simply use dfs to find the connected component
#include<iostream>
#include<vector>
using namespace std;

void dfs( vector<vector<int> >& graph,int node,vector<int>&visit){
    visit[node]=true;
    for(int a:graph[node]){
        if(visit[a]==false){
            dfs(graph,a,visit);
        }
    }
}

int main(){
    long n,m;
    cin>>n>>m;
   
    vector<vector<int> > graph(n+1);
    for(int i=0;i<m;i++){
     
        int a,b;
        cin>>a>>b;
     
        graph[a].push_back(b);
        graph[b].push_back(a);
        
    }
    vector<int> visit(n+1,false);
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(visit[i]==false){
            ans.push_back(i);
            dfs(graph,i,visit);
        }
    }
    if(ans.size()>1){
        cout<<ans.size()-1<<endl;
        for(int i=0;i<ans.size()-1;i++){
            cout<<ans[i]<<" "<<ans[i+1]<<endl;
        }
    }else{
        cout<<0<<endl;
    }
}