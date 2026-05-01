#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

template <typename t1, typename t2>
ostream &operator<<(ostream &os, pair<t1, t2> p)
{
    return os << "{" << p.first << ", " << p.second << "}";
}

template <typename t>
void printVec(vector<t> &v)
{
    for (ll i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return;
}

template <typename t, typename size_t>
void inputVec(vector<t> &v, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}

void pLine(ll line)
{
    cout << "Reached at Line: " << line << endl;
}

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
        ll n;
        cin >> n;

        vector<int> v(n);
        inputVec(v, n);

        sort(v.begin(), v.end());

        int s = 0, e = n - 1;
        if (((v[s] + v[e]) % 2) == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            ll ans = LLONG_MAX;

            // move s till parity changes
            bool div2S = (v[s] % 2);
            bool div2E = (v[e] % 2);

            while (s < n && v[s] % 2 == div2S)
            {
                s++;
            }

            ans = min(ans, n - (e - s + 1));

            s = 0;

            while (e >= 0 && v[e] % 2 == div2E)
            {
                e--;
            }

            ans = min(ans, n - (e - s + 1));

            cout << ans << endl;
        }
    }

    return 0;
}