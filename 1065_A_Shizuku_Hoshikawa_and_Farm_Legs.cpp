#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        if(n%2 == 1) {
            cout<<0<<endl;
            continue;
        }

        int max_chickens = n/2;
        int cnt = 1;
        while(max_chickens > 1){
            cnt++;
            max_chickens -= 2;
        }

        cout<<cnt<<endl;
    }

    return 0;
}