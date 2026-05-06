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

template <typename t, typename size_t>
void print2dVec(vector<vector<t>> &v, size_t &n, size_t &m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<bool>> isOk(n, vector<bool>(m, false));

        // first col is true
        for (int i = 0; i < n; i++)
        {
            isOk[i][0] = true;
        }

        // first row is true
        for (int i = 0; i < m; i++)
        {
            isOk[0][i] = true;
        }

        // cout << "Printing isOk after row and col = true" << endl;
        // print2dVec(isOk, n, m);

        vector<vector<int>> v(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                v[i][j] = s[j] - '0';
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!v[i][j])
                    break;
                isOk[i][j] = true;
            }
        }

        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (!v[i][j])
                    break;
                isOk[i][j] = true;
            }
        }

        bool fl = 1;
        for (int i = 0; i < n && fl; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] && !isOk[i][j])
                {
                    fl = 0;
                    break;
                }
            }
        }

        if (fl)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}