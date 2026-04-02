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
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int mx = 0;
        int mn = 0;
        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int new_mx = max(mx - a[i], b[i] - mn);
            int new_mn = min(mn - a[i], b[i] - mx); // uses old mx
            mx = new_mx;
            mn = new_mn;
        }
        cout << mx << endl;
    }
}