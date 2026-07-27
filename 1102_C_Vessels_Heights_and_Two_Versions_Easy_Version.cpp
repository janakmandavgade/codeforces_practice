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

template <typename t, typename size_t>
void input2dVec(vector<vector<t>> &v, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            cin >> v[i][j];
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

        vector<ll> v(n);
        inputVec(v, n);
        vector<ll> ans(n);
        for (ll k = 0; k < n; k++)
        {
            vector<ll> pmax(n);
            vector<ll> smax(n);

            // for pmax with k distance.
            pmax[0] = v[k];
            for (ll i = 1; i < n; i++)
            {
                pmax[i] = max(pmax[i - 1], v[(i + k) % n]);
            }

            smax[n - 1] = v[(k + n - 1) % n];
            for (ll i = n - 2; i >= 0; i--)
            {
                smax[i] = max(smax[i + 1], v[(k + i) % n]);
            }
            // cout << "For k = " << k << endl;
            // printVec(pmax);
            // printVec(smax);
            // vector<int> ans(n);
            ll sum = 0;
            for (ll i = 0; i + 1 < n; i++)
            {
                sum += min(pmax[i], smax[i + 1]);
            }
            ans[k] = sum;
            // ans
        }
        printVec(ans);
        // cout << endl;
    }

    return 0;
}