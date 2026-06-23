#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

#define MOD 1000000007

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

void dfs(ll curr, ll &vertices, vector<ll> &vis, vector<vector<ll>> &adj, vector<ll> &num_of_vertices)
{
    vis[curr] = 1;
    vertices++;

    for (auto &edge : adj[curr])
    {
        if (!vis[edge])
        {
            dfs(edge, vertices, vis, adj, num_of_vertices);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> adj(n + 1);

    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b, r_or_b;
        cin >> a >> b >> r_or_b;

        if (r_or_b == 0)
        {
            adj[b].push_back(a);
            adj[a].push_back(b);
        }
    }

    // Fixed Glitch 1
    vector<ll> vis(n + 1);
    vector<ll> num_of_vertices;
    ll num_of_components = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ll vertices = 0;
            dfs(i, vertices, vis, adj, num_of_vertices);
            num_of_vertices.push_back(vertices);
            num_of_components++;
        }
    }

    ll total_sequences = 1;
    for (ll i = 0; i < k; i++)
    {
        total_sequences = ((total_sequences % MOD) * n) % MOD;
    }

    ll bad_sequences = 0;
    for (ll i = 0; i < num_of_vertices.size(); i++)
    {
        ll num = 1;
        for (ll j = 0; j < k; j++)
        {
            num = ((num % MOD) * num_of_vertices[i]) % MOD;
        }
        bad_sequences = (bad_sequences + num) % MOD;
    }

    cout << (total_sequences - bad_sequences + MOD) % MOD << endl;

    return 0;
}