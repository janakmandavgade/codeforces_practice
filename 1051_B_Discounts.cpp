#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        vector<ll> b(k);
        for (ll i = 0; i < k; i++) {
            cin >> b[i];
        }

        // Sort prices descending
        sort(a.begin(), a.end());
        // Sort multi-vouchers descending to maximize their impact
        sort(b.begin(), b.end());

        ll id = n;
        for(ll i = 0 ; i < k ; i++){
            id -= b[i];
            if(id >= 0){
                sum -= a[id];
            }
        }

        cout<<sum<<endl;
    }
    return 0;
}