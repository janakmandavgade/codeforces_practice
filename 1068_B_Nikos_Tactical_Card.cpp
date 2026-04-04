#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long int ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n; i++)
            cin >> b[i];

        ll mx = 0;
        ll mn = 0;
        // ll ans = LLONG_MIN;

        for (ll i = 0; i < n; i++)
        {
            ll new_mx = max(mx - a[i], b[i] - mn);
            ll new_mn = min(mn - a[i], b[i] - mx); // uses old mx
            mx = new_mx;
            mn = new_mn;
        }
        cout << mx << endl;
    }
}