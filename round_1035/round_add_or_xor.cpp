#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c1,c2;
        cin>>b>>a>>c1>>c2;

        if(a<b){
            cout<<-1<<endl;
            continue;
        }
        int cost = 0;
        while(a!=b){
            if(a%2==1 && c2 < c1){
                cost+=c2;
            }
            else{
                cost+=c1;
            }
            a = a - 1;
        }
        cout<<cost<<endl;
    }
}