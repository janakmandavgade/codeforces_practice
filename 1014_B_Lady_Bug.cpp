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

        string a, b;
        cin >> a;
        cin >> b;

        int ones_even = 0, ones_odd = 0;
        int zeros_even = 0, zeros_odd = 0;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0 && a[i] == '1')
            {
                ones_even++;
            }
            else if (i % 2 == 1 && a[i] == '1')
            {
                ones_odd++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0 && b[i] == '0')
            {
                zeros_even++;
            }
            else if (i % 2 == 1 && b[i] == '0')
            {
                zeros_odd++;
            }
        }

        if (ones_even == 0 && ones_odd == 0)
        {
            cout << "YES" << endl;
        }
        else if (ones_even <= zeros_odd && ones_odd <= zeros_even)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}