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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> v(n, vector<char>(m));
    input2dVec(v, (size_t)n, (size_t)m);

    ll ways = 0;
    if (k == 1)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (v[i][j] == '.')
                {
                    ways++;
                }
            }
        }
    }
    else
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                int cnt = 0;
                while (j < m && v[i][j] == '.')
                {
                    cnt++;
                    j++;
                }
                // cout << "Count is:" << cnt << endl;
                // cout << i << " " << j << endl;
                if (cnt > 0)
                    j--;
                if (cnt >= k)
                    ways += (cnt - k + 1);
            }
        }
        // cout << ways << endl;

        for (ll j = 0; j < m; j++)
        {
            for (ll i = 0; i < n; i++)
            {
                int cnt = 0;
                while (i < n && v[i][j] == '.')
                {
                    cnt++;
                    i++;
                }
                // cout << "Count is:" << cnt << endl;
                // cout << i << " " << j << endl;
                if (cnt > 0)
                    i--;
                if (cnt >= k)
                    ways += (cnt - k + 1);
            }
        }
    }

    cout << ways << endl;

    return 0;
}