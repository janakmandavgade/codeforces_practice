#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> dishes(n);
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < n ; i++){
            cin>>dishes[i];
            mpp[dishes[i]]++;
        }
        
        int idx = -1;
        int mx = INT_MIN;
        for(auto [key, val]: mpp){
            if(mx < key) {
                mx = key;
                idx = val;
            }
        }

        cout<<idx<<endl;
    }
}