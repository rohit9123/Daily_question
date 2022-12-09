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

void solve();
// [1,2,3,4,5];
// [1,3,2,4,5];
// [5,4,2,3,1];
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n),ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int> index;
    unordered_map<int,int> no;
    for(int i=0;i<n;i++){
        index[i]=arr[i];
        no[arr[i]]=i;
    }
    int rev=0;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            rev^=1;
        }else if(type==2){
            int a,b;
            cin>>a>>b;
            if(!rev){
                int no1=index[a-1];
                int no2=index[b-1];
                no[no1]=b-1;
                no[no2]=a-1;
                index[a-1]=no2;
                index[b-1]=no1;
            }else{
                a--,b--;
                int index1=n-a;
                int index2=n-b;
                int no1=index[index1];
                int no2=index[index2];
                no[no1]=index2;
                no[no2]=index1;
                index[index2]=no1;
                index[index1]=no2;

            }
        }else{
            int k;cin>>k;
            if(!rev){
                cout<<no[k]+1<<endl;
            }else{
                cout<<n-no[k]<<endl;
            }
        }
    }
    // for(int a:ans){
    //     cout<<a<<" ";
    // }
}