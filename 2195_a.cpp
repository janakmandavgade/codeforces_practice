#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> v(n);

        bool isOne = false, is67 = false;
        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
            if(v[i] == 1) isOne = true;  
            if(v[i] == 67) is67 = true;  
        }

        if(isOne && is67) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}