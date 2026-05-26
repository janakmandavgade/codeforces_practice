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

    ll n, m;
    cin >> n >> m;

    vector<ll> row(n), col(m);

    inputVec(row, n);
    inputVec(col, m);

    vector<vector<ll>> v(n, vector<ll>(m, -1));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < row[i]; j++)
        {
            v[i][j] = 1;
        }
        if (row[i] < m)
            v[i][row[i]] = 0;
    }

    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < col[i]; j++)
        {
            if (v[j][i] == 0)
            {
                cout << 0 << endl;
                return 0;
            }
            v[j][i] = 1;
        }
        // Only set EMPTY if it falls inside the grid boundaries
        if (col[i] < n)
        {
            // Check contradiction: if row marked it FULL, but col wants it EMPTY
            if (v[col[i]][i] == 1)
            {
                cout << 0 << "\n";
                return 0;
            }
            v[col[i]][i] = 0;
        }
    }

    ll cnt = 1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (v[i][j] == -1)
            {
                cnt = cnt * 2 % (1000000007);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}