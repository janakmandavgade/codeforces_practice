#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <math.h>
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

        ll px, py, qx, qy;
        cin >> px >> py >> qx >> qy;

        ll d = (px - qx) * (px - qx) + (py - qy) * (py - qy);

        ll L = -1, sum = 0;
        vector<ll> v(n);

        inputVec(v, n);
        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            L = max(L, v[i]);
        }

        if (d < L * L)
        {
            if ((2 * L - sum <= 0) || (((2 * L - sum) * (2 * L - sum)) <= d))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            if (d <= sum * sum)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}