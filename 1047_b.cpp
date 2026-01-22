#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
        }
        int three_mul = n + 1;
        // if(n%3 != 0){
        //     three_mul += 3;
        // }
        // cout<<three_mul<<endl;

        for(int i = 0 ; i < n ; i++){
            int ans = three_mul - v[i];
            if(ans == 0) ans = three_mul;
            cout<< ans <<" ";
        }
        cout<<endl;
    }
}