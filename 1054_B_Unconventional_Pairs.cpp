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

        sort(v.begin(), v.end());

        int mx = -1;
        for(int i = 1 ; i < n ; i+=2){
            // cout<< v[i] << " - " << v[i-1] << "=" << abs(v[i] - v[i-1]) << endl;
            mx = max(mx, abs(v[i] - v[i-1]));
        }

        cout<<mx<<endl;
    }
}