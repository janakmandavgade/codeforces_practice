#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> v(n);
        ll sum = 0;
        ll mx = 0;
        for(ll i = 0 ; i < n ; i++) {
            cin>>v[i];
            sum += v[i];
            if(v[i] > 0) mx++;
        }

        bool val_found = false;
        for(ll i = mx ; i >= 0 ; i--){
            if(sum - i >= n - 1){
                cout<<i<<endl;
                val_found = true;
                break;
            }
        }

        if(!val_found){
            cout<<-1<<endl;
        }
        
    }

    return 0;
}