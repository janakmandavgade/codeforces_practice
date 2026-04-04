#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;

        ll mx = LLONG_MIN;
        ll start = 0;

        for(ll i = 0; i < n; i++){
            ll a, b, c;
            cin >> a >> b >> c;
            mx = max(mx, a*b - c);
            start += a * (b - 1);  // free jumps from ALL types
        }

        x -= start;

        if(x <= 0){
            cout << 0 << "\n";
            continue;
        }
        if(mx <= 0){
            cout << -1 << "\n";
            continue;
        }

        cout << (x + mx - 1) / mx << "\n";
    }

    return 0;
}