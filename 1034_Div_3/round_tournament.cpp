#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,j,k;
        cin>>n>>j>>k;
        int j_value = -1;
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++){
            
            cin>>v[i];
            if(i == (j - 1)){
                j_value = v[i];
            }
        }
        if(k > 1) cout<<"YES"<<endl;

        else{
            int mx = INT_MIN;
            for(int i = 0 ; i < n ; i++){
                mx = max(mx,v[i]);
            }
            if(j_value == mx){
                cout<<"Yes"<<endl;
            }
            else cout<<"No"<<endl;
        }
    }
}