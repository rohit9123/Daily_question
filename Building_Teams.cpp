//Question Link->https://cses.fi/problemset/result/4552304/
//Name->Building Teams
//Author->Rohit Kumar
//Status->Accepted
//Time_complexity->O(n)
//idea-> so we have to divide the student into two group so that no student from same group have any friend
// so it is a bipartite graph so we can use bfs to find the group
//bipartite graph we have to color the node with two color
//so we can use bfs to find the group
#include<iostream>
#include<vector>

using namespace std;
bool dfs(int node,vector<vector<int> >&graph,int color,vector<int>&ans){
    ans[node]=color;
    for(int a:graph[node]){
        if(ans[a]==0){
            bool answ=dfs(a,graph,color==1?2:1,ans);
            if(answ==false){
                return false;
            }
        }else if(ans[node]==ans[a]){
            return false;
        }
    }
    return true;
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
    vector<int> ans(n+1,0);
    for(int i=1;i<=n;i++){
        if(ans[i]==0){
            bool answ=dfs(i,graph,1,ans);
            if(answ==false){
                // cout<<i<<endl;
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}