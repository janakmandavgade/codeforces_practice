#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long int ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, cycle;
        cin>>n>>cycle;

        // find same values 
        vector<ll> v(n);
        for(ll i = 0 ; i < n ; i++){
            cin>>v[i];
        }

        bool isValid = true;
        for(ll i = 0 ; i < n ; i++){
            ll j = i;
            ll cnt = 0;
            while(j + 1 < n && v[j] == v[j+1]){
                j++;
            }
            // cout<<"i and j " << i << " " << j << endl; 
            if(j - i + 1>= cycle){
                cout<<"No"<<endl;
                isValid = false;
                break;
            }
            i = j;
        }

        if(isValid) cout<<"Yes"<<endl;

    }
}