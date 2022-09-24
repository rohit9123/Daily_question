#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[m],b[m];
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(a[i]==a[j]&&b[i]==b[j]){
                cout<<2<<endl;
                cout<<a[i]<<" "<<b[i]<<" "<<a[j]<<endl;
                return 0;
            }
            if(a[i]==b[j]&&b[i]==a[j]){
                cout<<2<<endl;
                cout<<a[i]<<" "<<b[i]<<" "<<b[j]<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}