#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
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
        {
            cin >> v[i][j];
        }
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
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> v(n, vector<ll>(m, 0));
    input2dVec(v, n, m);

    ll cnt_b = 0, cnt_w = 0;

    // row wise
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll cnt_b = 0, cnt_w = 0;
        for (ll j = 0; j < m; j++)
        {
            if (v[i][j] == 1)
            {
                cnt_b++;
            }
            else if (v[i][j] == 0)
            {
                cnt_w++;
            }
        }
        ans += ((1LL << cnt_b) - 1) + ((1LL << cnt_w) - 1);
    }

    // Col wise
    for (ll j = 0; j < m; j++)
    {
        ll cnt_b = 0, cnt_w = 0;
        for (ll i = 0; i < n; i++)
        {
            if (v[i][j] == 1)
            {
                cnt_b++;
            }
            else if (v[i][j] == 0)
            {
                cnt_w++;
            }
        }
        ans += ((1LL << cnt_b) - 1) + ((1LL << cnt_w) - 1);
    }

    cout << ans - n * m << endl;

    return 0;
}