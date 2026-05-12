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

template <typename t>
void print2dVec(vector<vector<t>> &v)
{
    for (ll i = 0; i < v.size(); i++)
    {
        for (ll j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
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
    ll n, k;
    cin >> n >> k;

    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    if (k > 2 * n - 1)
    {
        cout << 0 << endl;
    }
    else if (k == 2 * n - 1)
    {
        cout << 1 << endl;
    }
    else
    {
        ll x = ((k - 1) / 2LL);
        if (k > n)
        {
            ll smallest_a = k - n;
            cout << x - smallest_a + 1 << endl;
        }
        else if (k == n)
        {
            cout << x << endl;
        }
        else
        {
            cout << x << endl;
        }
    }

    return 0;
}

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     ll n, k;
//     if (!(cin >> n >> k))
//         return 0;

//     // 1. The absolute maximum 'a' can be is (k-1)/2 so that a < b.
//     ll x = (k - 1) / 2LL;

//     // 2. Your original structure:
//     if (k <= 2) // k=2 or less is impossible for two distinct positive integers
//     {
//         cout << 0 << endl;
//     }
//     else if (k > n)
//     {
//         // If k > n, b must be <= n, so a must be >= k - n.
//         ll smallest_a = k - n;

//         if (smallest_a > x)
//             cout << 0 << endl;
//         else
//             cout << x - smallest_a + 1 << endl;
//     }
//     else
//     {
//         // If k <= n, any 'a' from 1 up to x works.
//         // Example: n=10, k=6 -> x=2. Pairs: {1,5}, {2,4}.
//         cout << x << endl;
//     }

//     return 0;
// }