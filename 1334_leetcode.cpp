// question->https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// dijkstra algorithm->https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-in-plain-java-with-examples/
//so the question want to know how many city we can visit with the given distance threshold
//so we have to find the city with the smallest number of city we can visit with the given distance threshold
//so we have to find distance from one city to all other city
//so we can use dijkstra algorithm to find the distance from one city to all other city 
//it will take nlogn for one city
//so we can use for n city we have time complexity of n^2logn
//as we have only at max 100 node so we can take the complexity of n^2logn

class Solution {
public:
    void find_distance(vector<vector<pair<int,int> > >&graph,int node,vector<int>&ans,int max_distance){
        int n=ans.size();
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
        pq.push({0,node});
        vector<int> visited(n,1e9);
        
        while(!pq.empty()){
            pair<int,int> shortest=pq.top();
            pq.pop();
            int curr_node=shortest.second,distance=shortest.first;
            visited[curr_node]=min(visited[curr_node],distance);
            for(pair<int,int> child:graph[curr_node]){
                int child_node=child.first;
                int child_dist=distance+child.second;
                if(child_dist>max_distance||visited[child_node]<child_dist)continue;
                pq.push({child_dist,child_node});
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]!=1e9){
                count++;
            }
        }
        ans[node]=count;
        
    }
    
    
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int,int> > >graph(n);
        vector<int> ans(n,0);
        for(int i=0;i<edges.size();i++){
            int node1=edges[i][0],node2=edges[i][1],weight=edges[i][2];
            graph[node1].push_back({node2,weight});
            graph[node2].push_back({node1,weight});
        }
        
        for(int i=0;i<n;i++){
            find_distance(graph,i,ans,distanceThreshold);
        }
        int node=-1,reach=1e9;
        for(int i=0;i<n;i++){
            if(reach>=ans[i]){
                reach=ans[i];
                node=i;
            }
        }
        return node;
    }
};