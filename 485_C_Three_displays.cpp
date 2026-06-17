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

ll scanLeft(vector<ll> &font, vector<ll> &cost, ll end)
{
    ll curr_font = font[end];
    ll lmin = LLONG_MAX;
    for (ll i = 0; i < end; i++)
    {
        if (curr_font > font[i])
        {
            lmin = min(cost[i], lmin);
        }
    }
    return lmin;
}

ll scanRight(vector<ll> &font, vector<ll> &cost, ll start)
{
    ll curr_font = font[start - 1];
    ll rmin = LLONG_MAX;
    for (ll i = start; i < font.size(); i++)
    {
        if (curr_font < font[i])
        {
            rmin = min(cost[i], rmin);
        }
    }
    return rmin;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> font(n, 0), cost(n, 0);

    inputVec(font, n);
    inputVec(cost, n);

    ll ans = LLONG_MAX;
    for (ll j = 1; j < n - 1; j++)
    {
        ll lmin = scanLeft(font, cost, j);
        ll rmin = scanRight(font, cost, j + 1);

        if (lmin == LLONG_MAX || rmin == LLONG_MAX)
        {
            continue;
        }

        ans = min(ans, lmin + rmin + cost[j]);
    }

    cout << ((ans == LLONG_MAX) ? -1 : ans) << endl;

    return 0;
}