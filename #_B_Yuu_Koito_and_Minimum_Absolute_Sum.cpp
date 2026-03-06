#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> v(n);

        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
        }

        if(v[0] == -1 && v[n-1] == -1){
            v[0] = 0;
            v[n-1] = 0;
        } else if(v[0] == -1){
            v[0] = v[n-1];
        }else if(v[n-1] == -1){
            v[n-1] = v[0];
        }

        for(int i = 1 ; i < n-1 ; i++){
            if(v[i] == -1) v[i] = 0;
        }

        cout<<abs(v[n-1] - v[0])<<endl;
        for(int i = 0 ; i < n ; i ++){
            cout<<v[i]<<" ";
        }cout<<endl;

    }
}