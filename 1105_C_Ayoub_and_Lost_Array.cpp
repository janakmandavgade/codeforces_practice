#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

#define mod 1000000007

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

ll recur(ll pos, ll curr_rem, vector<ll> &rem, ll n, vector<vector<ll>> &dp)
{
    if (pos == n)
    {
        return (curr_rem == 0 ? 1 : 0);
    }

    if (dp[pos][curr_rem] != -1)
    {
        return dp[pos][curr_rem];
    }

    ll pick_0 = (rem[0] % mod) * (recur(pos + 1, curr_rem, rem, n, dp) % mod);
    ll pick_1 = (rem[1] % mod) * (recur(pos + 1, (curr_rem + 1) % 3, rem, n, dp) % mod);
    ll pick_2 = (rem[2] % mod) * (recur(pos + 1, (curr_rem + 2) % 3, rem, n, dp) % mod);

    return dp[pos][curr_rem] = ((pick_0 % mod) + (pick_1 % mod) + (pick_2 % mod)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, l, r;
    cin >> n >> l >> r;

    vector<ll> rem(3, 0);
    vector<vector<ll>> dp(n + 1, vector<ll>(3, -1));

    // for (ll i = l; i <= r; i++)
    // {
    //     rem[i % 3]++;
    // }

    // what is l % 3
    // rem(1) -> 3 add rem(1) + 1 and rem(2) + 1
    // rem(2) -> 3 add rem(2) + 1

    // rem[1]++;
    // rem[2]++;
    rem[0] += (r - l + 1) / 3;
    rem[1] += (r - l + 1) / 3;
    rem[2] += (r - l + 1) / 3;

    if ((r - l + 1) % 3 == 1)
    {
        rem[l % 3]++;
    }
    else if ((r - l + 1) % 3 == 2)
    {
        rem[l % 3]++;
        rem[(l + 1) % 3]++;
    }

    // printVec(rem);
    ll ans = recur(0, 0, rem, n, dp);
    cout << ans << endl;

    return 0;
}