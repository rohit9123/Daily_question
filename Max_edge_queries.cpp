//link ->https://www.interviewbit.com/problems/max-edge-queries/
// Time: O(QN) //if we use brute force then it will be O(Q*depth of nodes)
// Time: O(Qlog(depth of nodes)) where Q is number of queries and N is number of depth in the tree by using binary lifting
// Space: O(N*19)
//binary lifting is love
#include<bits/stdc++.h>
vector<vector<pair<int,int> > > tree;
vector<vector<pair<int,int> > > binary_lifting;
unordered_map<int,int> depth;

void binary_lift(int node,int parent,int weight,int dep){
    //bulid the binary lifting tree
    if(parent!=-1){
        binary_lifting[node][0]={parent,weight};
    }
    depth[node]=dep;
    for(int i=1;i<19;i++){
        int parent=binary_lifting[node][i-1].first;
        if(parent==-1){
            break;
        }
        binary_lifting[node][i].first=binary_lifting[parent][i-1].first;
        binary_lifting[node][i].second=max(binary_lifting[node][i-1].second,binary_lifting[parent][i-1].second);
    }
    for(pair<int,int> child:tree[node]){
        if(child.first!=parent){
            binary_lift(child.first,node,child.second,dep+1);
        }
    }
}

vector<int> Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    tree.clear();
    binary_lifting.clear();
    depth.clear();
    int n=A.size()+2;
    tree.resize(n);
    binary_lifting.resize(n,vector<pair<int,int> >(19,{-1,-1}));
    for(vector<int> a:A){
        //construct the tree
        int node1=a[0],node2=a[1],weight=a[2];
        tree[node1].push_back({node2,weight});
        tree[node2].push_back({node1,weight});
    }
    vector<int> answer;
    binary_lift(1,-1,0,0);
    for(int k=0;k<B.size();k++){
        int node1=B[k][0],node2=B[k][1];
        if(depth[node1]<depth[node2])swap(node1,node2);
        int diff=depth[node1]-depth[node2];
        int ans=0;
        for(int i=0;i<=18;i++){
            if((1<<i)&diff){
                ans=max(ans,binary_lifting[node1][i].second);
                node1=binary_lifting[node1][i].first;
            }
        }
        if(node1==node2){
            answer.push_back(ans);
            continue;
        }
        for(int i=18;i>=0;i--){
            if(binary_lifting[node1][i].first!=binary_lifting[node2][i].first){
                ans=max(ans,max(binary_lifting[node1][i].second,binary_lifting[node2][i].second));
                node1=binary_lifting[node1][i].first;
                node2=binary_lifting[node2][i].first;
            }
        }
         ans=max(ans,max(binary_lifting[node1][0].second,binary_lifting[node2][0].second));
         answer.push_back(ans);
    }
    return answer;
}
