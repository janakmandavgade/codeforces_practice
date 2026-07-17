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

// int dfs(int curr, vector<vector<int>> &adj, vector<bool> &vis, bool flowrisa_present, bool bee_present, int fIdx, int bIdx)
// {
//     // if (vis[curr])
//     // {
//     //     cout << "Curr is visited:" << curr << endl;
//     //     return 0;
//     // }
//     if (curr == fIdx)
//     {
//         // cout << "Changed Flowrisa_present" << endl;
//         flowrisa_present = true;
//     }

//     if (flowrisa_present && curr == bIdx)
//     {
//         // cout << "Changed bee_present" << endl;
//         bee_present = true;
//     }

//     ll sum = 0;
//     if (flowrisa_present && bee_present)
//     {
//         // cout << "flowrisa_present && bee_present" << endl;
//         sum = 1;
//     }

//     // int sum = 0;
//     vis[curr] = true;
//     for (auto &neigh : adj[curr])
//     {
//         // cout << "Inside Loop of dfs." << endl;
//         if (!vis[neigh])
//         {
//             // cout << "Before sum and visiting:" << neigh << endl;
//             sum += dfs(neigh, adj, vis, flowrisa_present, bee_present, fIdx, bIdx);
//             // cout << "After sum" << endl;
//         }
//     }

//     return sum;
// }

int dfs(int curr, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &sub, vector<int> &chk_sub, int x, int y)
{
    vis[curr] = true;
    sub[curr] = 1;

    if (curr == x)
    {
        chk_sub[curr] = true;
    }
    else
        chk_sub[curr] = false;

    for (auto neigh : adj[curr])
    {
        if (!vis[neigh])
        {
            sub[curr] += dfs(neigh, vis, adj, sub, chk_sub, x, y);
            chk_sub[curr] |= chk_sub[neigh];
        }
    }

    return sub[curr];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, flowrisa, bee;
    cin >> n >> flowrisa >> bee;

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // cout << "After Input" << endl;

    // int pathsContainingBoth = 0;
    // // Find paths which have flowrisa and beehive in them in order.
    // for (int src = 1; src <= n; src++)
    // {
    //     vector<bool> vis(n + 1, false);
    //     // bool flowrisa_present = ((src == flowrisa) ? true : false);
    //     // bool bee_present = ((src == bee) ? true : false);
    //     // cout << "Before DFS" << endl;
    //     pathsContainingBoth += dfs(src, adj, vis, false, false, flowrisa, bee);
    //     // cout << "After DFS" << endl;

    //     // cout << pathsContainingBoth << endl;
    // }

    // cout << ((n * (n - 1))) - pathsContainingBoth << endl;

    vector<int> sub(n + 1), parentV(n + 1), chk_sub(n + 1);
    vector<bool> vis(n + 1);

    dfs(bee, vis, adj, sub, chk_sub, flowrisa, bee);

    ll fin = 0;

    for (int v : adj[bee])
    {
        if (chk_sub[v] == true)
        {
            fin = sub[bee] - sub[v];
            break;
        }
    }

    cout << 1LL * n * (n - 1) - 1LL * sub[flowrisa] * fin << endl;

    return 0;
}

// #include <iostream>
// #include <cstdio>
// #include <vector>
// using namespace std;

// const int MAXN = 3e5;

// int n, m, u, v, x, y, sub_size[MAXN + 5];
// bool vis[MAXN + 5], chk_sub[MAXN + 5];
// vector<int> adj[MAXN + 5];

// int DFS(int u)
// {
//     vis[u] = true;
//     sub_size[u] = 1;
//     if (u == x)
//         chk_sub[u] = true;
//     else
//         chk_sub[u] = false;
//     for (int v : adj[u])
//         if (!vis[v])
//         {
//             sub_size[u] += DFS(v);
//             chk_sub[u] |= chk_sub[v];
//         }
//     return sub_size[u];
// }

// int main()
// {
//     scanf("%d%d%d", &n, &x, &y);
//     m = n - 1;
//     while (m--)
//     {
//         scanf("%d%d", &u, &v);
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     DFS(y);

//     long long fin;
//     for (int v : adj[y])
//         if (chk_sub[v])
//         {
//             fin = sub_size[y] - sub_size[v];
//             break;
//         }

//     printf("%I64d", 1LL * n * (n - 1) - fin * sub_size[x]);
//     return 0;
// }