//Question Link->https://cses.fi/problemset/task/1667/
//Name->Message Route
//Author->Rohit Kumar
//Status->Accepted
//Time_complexity->O(n)
//Space_complexity->O(n)
//idea-> so we have to find the shortest path from 1 to n
//so first we have to check wether we can go to destination or not
//as it is undirected and unweighted graph so we can use bfs to find the shortest path
//and we have to also track there parent so we can find the path


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int> >& graph,int src,int dest){
    vector<int> visit(graph.size(),false);
    vector<int> parent(graph.size(),-1);
    queue<int> q;
    q.push(src);
    visit[src]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int a:graph[node]){
            if(visit[a]==false){
                visit[a]=true;
                parent[a]=node;
                q.push(a);
            }
        }
    }
    if(visit[dest]==false){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        vector<int> ans;
        int node=dest;
        while(node!=-1){
            ans.push_back(node);
            node=parent[node];
        }
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
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
    bfs(graph,1,n);
}