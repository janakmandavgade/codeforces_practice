#include <bits/stdc++.h>
using namespace std;

void printvec(vector<int>& v){
    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;

        vector<int> a(n), b(n);

        for(int i = 0 ; i < n ; i++){
            cin>>a[i];
        }
        for(int i = 0 ; i < n ; i++){
            cin>>b[i];
        }
        // cout<<"ENDE"<<endl;
        int last_idx = n - 1;
        a[last_idx] = (a[last_idx] < b[last_idx]) ? b[last_idx] : a[last_idx]; 
        
        // cout<<a[last_idx]<<endl;

        vector<int> ps(n);
        for(int i = n - 2 ; i >= 0 ; i--){
            a[i] = max({a[i], b[i], a[i+1]});
        }
        
        // cout<<a[0]<<endl;
        // printvec(a);

        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += a[i];
            ps[i] = sum;
        }
        
        // cout<<ps[n-1]<<endl;
        // printvec(ps);

        while(q--){
            int l, r;
            cin>>l>>r;

            if(l-1 == 0) cout<<ps[r-1]<<" ";
            else{
                cout<<ps[r-1]-ps[l-2]<<" ";
            }
        }
        cout<<endl;
    }
}