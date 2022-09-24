
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
struct rem_your_index{
    int start,end,index;
};
static bool mysrt(rem_your_index&a,rem_your_index&b){
    if(a.start==b.start){
        return a.end>b.end;
    }
    return a.start<b.start;
}
int main(){
    int n;
    cin>>n;
    vector<rem_your_index> ok(n);
    for(int i=0;i<n;i++){
        cin>>ok[i].start>>ok[i].end;
        ok[i].index=i;
    }
    sort(ok.begin(),ok.end(),mysrt);
    vector<int> max_dis(n);
    vector<int> max_dis_left(n);
    max_dis[0]=ok[0].end;
    max_dis_left[n-1]=ok[n-1].end;
    for(int i=1;i<n;i++){
        max_dis[i]=max(max_dis[i-1],ok[i].end);
        max_dis_left[n-i-1]=min(max_dis_left[n-i],ok[n-i-1].end);
    }
    
    vector<int> inn(n);
    vector<int> isske_andr(n);
    for(int i=1;i<n;i++){
        if(max_dis[i-1]>=ok[i].end){
            inn[ok[i].index]=1;
        }

    }
    for(int i=0;i<n-1;i++){
        if(ok[i].end>=max_dis_left[i+1]){
            isske_andr[ok[i].index]=1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<isske_andr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<inn[i]<<" ";
    }

}