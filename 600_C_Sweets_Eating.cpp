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

    ll n, m;
    cin >> n >> m;

    vector<ll> v(n + 1, 0);
    vector<ll> psum(n + 1, 0);

    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        sum += v[i];
        psum[i] += sum;
    }

    // printVec(psum);
    vector<ll> dp(n + 1, 0);
    for (ll k = 1; k <= n; k++)
    {
        ll ans = 0;
        ll curr_idx = k;
        dp[k] = psum[k] + dp[max(0LL, k - m)];

        // cout << ans << " ";
    }
    // cout << endl;

    // printVec(dp);
    for (ll i = 1; i <= n; i++)
        cout << dp[i] << " ";
    cout << endl;

    return 0;
}