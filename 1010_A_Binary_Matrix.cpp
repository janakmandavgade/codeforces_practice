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
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        bool isOnePresent = false;

        // vector<vector<ll>> v(n, vector<ll>(m, -1));
        vector<ll> row(n, 0), col(m, 0);

        int current_xor = 0;
        for (ll i = 0; i < n; i++)
        {
            current_xor = 0;
            string s;
            cin >> s;
            for (ll j = 0; j < m; j++)
            {
                ll ele = s[j] - '0';
                if (ele == 1)
                {
                    isOnePresent = true;
                    row[i] = (row[i] + 1) % 2;
                    col[j] = (col[j] + 1) % 2;
                }
            }
        }

        if (!isOnePresent)
        {
            cout << 0 << endl;
            continue;
        }

        ll cnt = 0;
        // for (ll i = 0; i < n; i++)
        // {
        //     for (ll j = 0; j < m; j++)
        //     {
        //         if (row[i] == 1 && col[j] == 1)
        //         {
        //             cnt++;
        //             row[i] = 0;
        //             col[j] = 0;
        //         }
        //         // else if (row[i] == 1)
        //         // {
        //         //     cnt++;
        //         //     row[i] = 0;
        //         // }
        //         // else if (col[j] == 1)
        //         // {
        //         //     cnt++;
        //         //     col[j] = 0;
        //         // }
        //     }
        // }

        ll row_cnt = 0, col_cnt = 0;
        for (auto &ele : row)
        {
            if (ele == 1)
                row_cnt++;
        }

        for (auto &ele : col)
        {
            if (ele == 1)
                col_cnt++;
        }

        cout << max(row_cnt, col_cnt) << endl;
    }

    return 0;
}