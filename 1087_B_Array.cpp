#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long int ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        vector<ll> v(n), ans(n);

        for(ll i = 0 ; i < n ; i++) cin>>v[i];

        for(ll i = 0 ; i < n ; i++){
            ll f1 = 0, f2 = 0;
            for(ll j = i+1 ; j < n ; j++){
                if(v[i] > v[j]) f1++;
                else if(v[i] < v[j]) f2++;
            }
            ans[i] = max(f1, f2);
        }

        for(ll e: ans) cout<<e<<" ";
        cout<<endl;
    }
}