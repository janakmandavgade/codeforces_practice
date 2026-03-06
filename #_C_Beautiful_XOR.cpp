#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;

        if(a < b){
            cout<<-1<<endl;
        }else if(a == b){
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
            int ans = a ^ b;
            cout<<ans<<endl;
        }
    }
}