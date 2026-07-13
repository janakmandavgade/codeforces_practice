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

ll recur(ll l, ll r, vector<ll> &v, vector<vector<ll>> &dp)
{
    if (l == r)
    {
        return v[l];
    }

    if (dp[l][r] != LLONG_MIN)
    {
        return dp[l][r];
    }

    ll ans = max(
        v[l] - recur(l + 1, r, v, dp),
        v[r] - recur(l, r - 1, v, dp));

    return dp[l][r] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> v(n);

    vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MIN));

    inputVec(v, n);

    ll totalSum = 0;
    for (ll i = 0; i < n; i++)
    {
        totalSum += v[i];
    }

    ll l = 0, r = n - 1;

    ll diff = recur(l, r, v, dp);

    // cout << ans << endl;
    cout << (totalSum + diff) / 2 << endl;

    return 0;
}