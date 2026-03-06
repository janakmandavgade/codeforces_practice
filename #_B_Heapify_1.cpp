#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<int>& v){
    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);

        for(int i = 0 ;i < n ; i++){
            cin>>v[i];
        }
        
        if(n == 1){
            cout<<"YES"<<endl;
            continue;
        }

        for(int i = 0 ; i < n ; i++){
            // cout<<i << " " << (2*(i+1)) - 1 << endl;
            if((2*(i+1)) - 1 >= n){break;}
            else if(v[i] > v[(2*(i+1)) - 1]){
                swap(v[i], v[(2*(i+1)) - 1]);
            }
            // print_vec(v);
        }
        
        // print_vec(v);

        bool isSorted = true;
        for(int i = 1; i < n ; i++){
            if(v[i-1] > v[i]) {isSorted = false; break;}
        }

        if(isSorted) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}