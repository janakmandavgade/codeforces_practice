#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

void printVec(vector<ll> &v){
    for(ll i = 0 ; i < v.size() ; i++) cout<<v[i]<<" ";
    cout<<endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        
        vector<int> v(n);
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
            mpp[v[i]]++;
        }

        int cnt = 0;
        for(auto [key, value]:mpp){
            if(key != value){
                if(value > key)
                    cnt += value - key;
                else    
                    cnt += value;
            }
        }

        cout<<cnt<<endl;
    }

    return 0;
}