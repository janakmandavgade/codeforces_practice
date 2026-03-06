#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> v(n);
        for(int i = 0 ; i < n ; i++ ){
            cin>>v[i];
        }

        if(n == 1) {cout<<1<<endl;continue;}

        bool isAsc = true;

        for(int i = 1 ; i < n ; i++){
            if(v[i-1] > v[i]) isAsc = false;
        }

        if(isAsc) cout<<n<<endl;
        else cout<<1<<endl;
        // cout<<n - c << endl;
    }
}