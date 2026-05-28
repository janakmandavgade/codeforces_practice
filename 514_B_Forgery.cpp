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
    ll n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m, NULL));

    input2dVec(v, n, m);

    vector<vector<char>> v2(n, vector<char>(m, '.'));

    for (ll row = 1; row < n - 1; row++)
    {
        for (ll col = 1; col < m - 1; col++)
        {
            ll cnt_hash = 0;
            for (int dr = -1; dr <= 1; dr++)
            {
                for (int dc = -1; dc <= 1; dc++)
                {
                    ll nr = row + dr;
                    ll nc = col + dc;

                    if (v[nr][nc] == '#' && !(nr == row && nc == col))
                        cnt_hash++;
                    // check if i have 8 '#' for current center
                    // then if yes, add it to v2
                }
            }
            // cout << "For row and col:" << row << ":" << col << " " << "Hash cnt is:" << cnt_hash << endl;
            if (cnt_hash == 8)
            {
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        ll nr = row + dr;
                        ll nc = col + dc;
                        // cout << "nr and nc " << nr << ":" << nc << endl;
                        if (nr == row && nc == col)
                            continue;

                        v2[nr][nc] = '#';
                        // cout << v2[nr][nc] << endl;
                    }
                }

                // cout << "After row and col:" << row << ":" << col << endl;
                // print2dVec(v2);
            }
        }
    }

    // print2dVec(v2);

    for (ll row = 0; row < n; row++)
    {
        for (ll col = 0; col < m; col++)
        {
            if (v2[row][col] != v[row][col])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}