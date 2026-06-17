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

void dfs(int row, int col, vector<vector<int>> &v, vector<vector<int>> &vis, vector<pair<int, int>> &store)
{
    if (row < 0 || col < 0 || row >= v.size() || col >= v.size() || v[row][col] == 1 || vis[row][col] == 1)
    {
        return;
    }
    vis[row][col] = 1;
    store.push_back({row, col});

    dfs(row - 1, col, v, vis, store);
    dfs(row, col - 1, v, vis, store);
    dfs(row + 1, col, v, vis, store);
    dfs(row, col + 1, v, vis, store);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

    pair<int, int> p1, p2;
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;

    // cout << "Taken input" << endl;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++)
        {
            v[i][j] = s[j] - '0';
        }
    }

    // cout << "Taken 2d input" << endl;

    // print2dVec(v);

    vector<vector<pair<int, int>>>
        islands;

    vector<pair<int, int>> island1, island2;

    vector<vector<int>> vis(n, vector<int>(n, 0));

    // cout << "Reached here" << endl;
    dfs(p1.first - 1, p1.second - 1, v, vis, island1);

    // printVec(island1);

    for (auto &row : vis)
    {
        fill(row.begin(), row.end(), 0);
    }

    dfs(p2.first - 1, p2.second - 1, v, vis, island2);
    // cout << "Reached here" << endl;
    // printVec(island2);

    int distance = INT_MAX;
    for (int i = 0; i < island1.size(); i++)
    {
        for (int j = 0; j < island2.size(); j++)
        {
            int r1 = island1[i].first + 1, r2 = island2[j].first + 1;
            int c1 = island1[i].second + 1, c2 = island2[j].second + 1;

            // if(r1 == r2 && c1 == c2)

            int curr_d = ((r1 - r2) * (r1 - r2)) + ((c1 - c2) * (c1 - c2));
            distance = min(distance, curr_d);
        }
    }

    cout << distance << endl;

    return 0;
}