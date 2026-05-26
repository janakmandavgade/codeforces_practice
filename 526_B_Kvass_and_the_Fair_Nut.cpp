#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
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

// void printVec(vector<ll> &v)
// {
//     for (ll i = 0; i < v.size(); i++)
//         cout << v[i] << " ";
//     cout << endl;
//     return;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    inputVec(v, n);

    ll mn = LLONG_MAX;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        mn = min(mn, v[i]);
        sum += v[i];
    }

    if (sum - k < 0)
    {
        cout << -1 << endl;
        return 0;
    }

    ll extras = 0;
    for (ll i = 0; i < n; i++)
    {
        extras += (v[i] - mn);
    }
    if (k > extras)
    {
        k -= extras;

        ll ans = (k + n - 1) / n;

        cout<<mn - ans << endl;
        return 0;
    }

    cout << mn << endl;
    return 0;
}