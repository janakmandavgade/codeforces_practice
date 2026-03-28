#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;

        vector<ll> v(n);

        ll tot_transactions = 0;
        for(ll i = 0 ; i < n ; i++){
            cin>>v[i];
            tot_transactions += (v[i]/x);
        }
        // cout<<tot_transactions<<endl;
        ll ans = LLONG_MIN;
        for(ll i = 0 ; i < n ; i++){
            ll val = v[i] + ((tot_transactions - (v[i]/x)) * y);
            // ll val = tot_transactions - (v[i]/x);
            // cout<<val<<endl;
            ans = max(ans, val);
        }

        cout<<ans<<endl;
    }

    return 0;
}