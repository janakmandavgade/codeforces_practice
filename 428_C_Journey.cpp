#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <iomanip>
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

void dfs(ll curr, vector<vector<ll>> &adj, vector<ll> &vis, double &ans, ll path_len, double prob)
{
    vis[curr] = 1;

    // if (adj[curr].empty())
    // {
    //     ans.push_back({path_len, curr});
    //     return;
    // }
    ll choices = 0;
    for (auto &ele : adj[curr])
    {
        if (!vis[ele])
        {
            choices++;
        }
    }

    if (choices == 0)
    {
        ans += path_len * prob;
        return;
    }

    for (auto &ele : adj[curr])
    {
        // cout << ele << " " << path_len << endl;
        if (!vis[ele])
            dfs(ele, adj, vis, ans, path_len + 1, prob / choices);
        // cout << ele << " " << path_len << endl;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

    vector<vector<ll>> adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        ll src, dest;
        cin >> src >> dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    // cout << "2d Vec:" << endl;
    // print2dVec(adj);

    vector<ll> vis(n + 1, 0);
    double ans = 0.0;

    // vis[1] = 1;
    dfs(1, adj, vis, ans, 0, 1.0);

    cout << fixed << setprecision(15);
    cout << ans << endl;

    return 0;
}