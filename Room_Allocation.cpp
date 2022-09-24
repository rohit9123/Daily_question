
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<string.h>
#include<math.h>
#include<unordered_map>
#include<iomanip>
#include<unordered_set>
 
#define rep(i,x,n) for(int i=x;i<n;i++)
#define ll long long
#define fs first
#define ss second
#define mod 1000000007
#define pb push_back
#define in insert
#define pres(c,x) ((c).find(x)!=c.end());
#define lli long long int
#define vl vector<ll>
#define mp(a,b) make_pair(a,b)
 
 
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
using namespace std;
struct room{
    int start,index,exit;
};
static bool mycmp(room& a,room& b){
    if(a.start==b.start){
       return a.exit<b.exit;
    }
    return a.start<b.start;
}
int main(){
    int n;
    cin>>n;
    vector<room> ok;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        room st;
        st.start=a,st.index=i,st.exit=0;
        ok.push_back(st);
        st.start=b,st.index=i,st.exit=1;
        ok.push_back(st);
    }
    sort(ok.begin(),ok.end(),mycmp);
    int rooms=0,maxi=0;

    vector<int> answer(n);
    priority_queue<int,vector<int>,greater<int> > pq;

    for(room a:ok){
        if(a.exit){
            pq.push(answer[a.index]);
            rooms--;
        }else{
            rooms++;
            if(pq.size()){
                answer[a.index]=pq.top();
                pq.pop();
            }else{
                answer[a.index]=rooms;
            }
            maxi=max(maxi,rooms);
        }
    }
    cout<<maxi<<endl;
    for(int a:answer){
        cout<<a<<" ";
    }
    

}