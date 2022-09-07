//Question Link->https://leetcode.com/problems/find-all-people-with-secret/
//Question Name->Find All People With Secret
//Question Category->Greedy
//Question Difficulty->Medium-hard(if you carck the question)
//Author->Rohit Kumar

//Approach -> so first of all only 2 person knows the secret 0 and firstperson 
//now how can other person know the sceret the must meet 0 or firstperson right
//so when a person meet 0 or firstperson he will know the secret
//the time when he meet 0 or firstperson is the time when he share the secret there
//if he meet before this time he will not know the secret
//so what is the approach as we know dijkstra is the best approach to find the shortest path
//so we know 0 and firstperson will know the secret at time=0 then we will update all there connection 
// that you will get sceret from 0 at this time you will know the secret
//know we simply take the person which have known the secret at lowest time because may be there is a way he can
//send the secret to other person in less time eg-> if 0 have meeting with 1 at=4 and 0 have meeting with 2 at=5
// and 1 have meeting with 2 at=4 so 1 can send the secret to 2 in less time and then 2 can send the secret to other person in less time
//what if person meet before the time when he know the secret then no one know the secret so we will not update the connection


//please upvote the solution if you like it


class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        vector<int> first(n,1e9);
        //we know that 0 and firstperson will know the secret at time=0
        first[firstPerson]=0;
        first[0]=0;

        //it will store the time when a person will know the secret 
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;

        vector<vector<pair<int,int> > >graph(n);
        for(int i=0;i<meetings.size();i++){
            int u=meetings[i][0],v=meetings[i][1],time=meetings[i][2];
            graph[u].push_back({v,time});
            graph[v].push_back({u,time});
            
        }
        //we push 0 and firstperson because the know secret at time =0;
        pq.push({0,0});
        pq.push({0,firstPerson});

        while(pq.size()){
            pair<int,int> top=pq.top();
            pq.pop();
            //we take the lowest time person and update all the connection
            int current_time=top.first,node=top.second;
            if(first[node]<current_time){
				//if we already visited this node in less time then all the connection are already know the screat at less time
                continue;
            }
            for(pair<int,int> a:graph[node]){
                if(a.second>=current_time&&first[a.first]>a.second){
                    first[a.first]=a.second;
                    pq.push({a.second,a.first});
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(first[i]!=1e9){
                ans.push_back(i);
            }
        }
        return ans;
    }
};