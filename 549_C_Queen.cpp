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

    vector<vector<int>> adj(t + 1);
    vector<int> respect(t + 1);

    int cnt = 1;
    while (cnt <= t)
    {
        ll parent, c;
        cin >> parent >> c;

        // adj[cnt].push_back(parent);
        if (parent != -1)
            adj[parent].push_back(cnt);
        respect[cnt] = c;

        cnt++;
    }

    // print2dVec(adj);
    bool atleast_one = false;
    for (int i = 1; i <= t; i++)
    {
        bool hasRespect = false;
        for (auto ele : adj[i])
        {
            if (respect[ele] == 0)
            {
                hasRespect = true;
                break;
            }
        }

        if (!hasRespect && respect[i])
        {
            cout << i << " ";
            atleast_one = true;
        }
    }
    cout << endl;

    if (atleast_one == false)
    {
        cout << -1 << endl;
    }

    return 0;
}