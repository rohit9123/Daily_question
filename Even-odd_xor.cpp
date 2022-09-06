// Question Link: https://codeforces.com/problemset/problem/1722/G
// Question Name: Even-odd xor
// Question Category: Greedy  bitmasks
// Question Difficulty: 1500
//desc -> we have construct a array such that xor of all even index is even and xor of all odd index is odd 
        // and every element is to be unique between 0 to 2^31 and length of array is 3<=n<=2*10^5
//approach-> so we know the most array length have 2*10^5 which is very less then 2^31 so what we can do
//we can simply assign value to even index such that the xor value of all index is not equal to 0
//and we can assign value to odd index such that xor value of all odd index is not equal to even xor and we leave 2 odd index
//no we will make array which will tell us which bit to set and which bit to unset to make xor value of even index is equal to odd index
//we simply take two no one set and one unset when ever we find a bit set we will set it in set and unset it in unset
//now we will simply assign value to (1<<29)+set and (1<<29)+unset so that xor value of all even index and odd index is equal 
//1<<29 will be cancel out and it will be also unique beacause 1<<29>2*10^5

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
#define f first
#define s second
#define mod 1000000007
#define pb push_back
#define in insert
#define pres(c,x) ((c).find(x)!=c.end());
#define lli long long int
#define vl vector<ll>
 
 
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
using namespace std;

void solve();

int main(){
    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
}

void solve(){
   int n;
   cin>>n;
   if(n==3){
    cout<<"2 1 3"<<endl;
    return;
   }
   vector<int> arr(n);
   int i=0,j=2;
   int count=0;
   int even=0,odd=0;
   for(int i=0;i<n;i+=2){
         arr[i]=j++;
         
         count++;
         int lasteven=even;
         even^=arr[i];
         
         if(even==0&&i+2>=n){
            arr[i]=(1<<27);
        
            even=lasteven^arr[i];
        }
    }
   
    i=1;
    int last_index=1;
   
    for(int i=1;i<n&&count<n-2;i+=2){
        arr[i]=j++;
        count++;
       
        last_index=i+2;
        int last_odd=odd;
        odd^=arr[i];
        if(odd==even&&count==n-2){
            arr[i]=(1<<28);
            odd=last_odd^arr[i];
        }
    }
    
   
    vector<int> bit_on(32,0);
    for(int i=0;i<31;i++){
        if(even&(1<<i)){
            bit_on[i]++;
            
        }
        if(odd&(1<<i)){
            bit_on[i]--;
            
        }
    }
    int two_number=0,second_no=0;
    for(int i=0;i<31;i++){
        if(bit_on[i]==1){
            two_number+=(1<<i);
        }else if(bit_on[i]==-1){
           
            second_no+=(1<<i);
            
        }
    }
    
    arr[last_index]=(1<<29)+(two_number);
    arr[last_index+2]=(1<<29)+(second_no);
    int even1=0,odd1=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            even1^=arr[i];
        }else{
            odd1^=arr[i];
        }
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    

}