#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

void printVec(vector<ll> &v)
{
    for (ll i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        vector<ll> v(m);
        for (auto &it : v)
            cin >> it;
        bool atleast_1_decreasing = false;

        for (int i = 0; i < m; i++)
        {
            // cout << i - 1 << " " << (v[i - 1] >= v[i]) << endl;
            if (i - 1 >= 0 && v[i - 1] >= v[i])
            {
                atleast_1_decreasing = true;
                break;
            }
        }

        if (atleast_1_decreasing)
        {
            cout << 1 << endl;
        }
        else
        {
            int val = v[m - 1];
            int cnt = n - val + 1;
            cout << cnt << endl;
        }
    }

    return 0;
}