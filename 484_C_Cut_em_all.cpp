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

bool isLeaf(ll curr, vector<vector<ll>> &adj, vector<bool> &vis)
{
    for (auto ele : adj[curr])
    {
        if (!vis[ele])
            return false;
    }
    return true;
}

ll dfs(ll curr, vector<vector<ll>> &adj, vector<bool> &vis, ll &ans)
{
    if (isLeaf(curr, adj, vis))
    {
        return 1LL;
    }
    vis[curr] = true;

    ll total_sz = 1;
    for (auto &ele : adj[curr])
    {
        if (!vis[ele])
            total_sz += dfs(ele, adj, vis, ans);
    }

    if (curr != 0 && total_sz % 2 == 0)
        ans++;

    return total_sz;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<vector<ll>> adj(n);
    vector<bool> vis(n, 0);

    ll ans = 0;

    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;

        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    vis[0] = 1;

    // cout << "Here" << endl;

    dfs(0, adj, vis, ans);

    // cout << "Vertices:" << n << endl;

    cout << ((n % 2 == 1) ? -1 : ans) << endl;

    return 0;
}