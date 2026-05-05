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
        ll n, x;
        cin >> n >> x;
        ll val = 1;
        ll cnt = 0;
        ll sum = 0;

        if (n == 1 && x == 0)
        {
            cout << -1 << endl;
        }

        for (ll i = 0; i < 64; i++)
        {
            if ((x >> i) && 1)
            {
                sum += val;
                cnt++;
            }
            val *= 2;
        }

        cout << sum << endl;

        if ((n - cnt) % 2 == 0)
        {
            sum += (n - cnt);
        }
        else
        {
            sum += ((n - cnt - 1) + 2);
        }

        cout << sum << endl;
    }

    return 0;
}