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
        int mx = INT_MIN;
        int mn = INT_MAX;

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            mpp[v[i]]++;
        }

        bool done = false;
        for (auto &[k, v] : mpp)
        {
            if (v >= 2)
            {
                cout << "YES" << endl;
                done = true;
                break;
            }
        }

        if (!done)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}