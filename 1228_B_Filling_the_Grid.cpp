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

bool CheckIfF(int i, int j, vector<ll> &row, vector<ll> &col)
{
    if (i < col[j] || j < row[i])
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<ll> row(n), col(m);
    inputVec(row, n);
    inputVec(col, m);

    // Step 1: check conflicts
    for (int i = 0; i < n; i++)
    {
        if (row[i] < m && col[row[i]] > i)
        {
            cout << 0;
            return 0;
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (col[j] < n && row[col[j]] > j)
        {
            cout << 0;
            return 0;
        }
    }

    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            // cout << "i:" << i << " j:" << j << endl;

            // if (row[i] == 0 && col[j] == 0)
            // {
            //     // cout << "E" << " " << endl;
            //     continue;
            // }
            // else if (i < col[j] || j < row[i])
            // {
            //     // cout << "F" << " " << endl;
            //     continue;
            // }
            // // if (i == 3 && j == 2)
            // // {
            // // cout << (((i - 1) < col[j] || j < row[i]) || (i < col[j] || (j - 1) < row[i])) << endl;
            // // }
            // else if (

            //     (((i - 1) >= 0 && (j - 1) >= 0) &&
            //      ((i - 1) < col[j] || j < row[i])) ||
            //     (i < col[j] || (j - 1) < row[i]))

            // {
            //     // cout << "X" << " " << endl;
            //     continue;
            // }
            // else
            //     cnt++;

            if (j > row[i] && i > col[j])
                cnt++;
        }
        // cout << endl;
    }

    // cout << pow(2, (int)cnt) % (1e9 + 7) << endl;

    if (cnt != 0)
    {
        long long ans = 1;
        long long MOD = 1000000007LL;

        for (int i = 0; i < cnt; i++)
        {
            ans = (ans * 2) % MOD;
        }

        cout << ans << endl;
    }
    else
    {
        cout << cnt << endl;
    }

    return 0;
}