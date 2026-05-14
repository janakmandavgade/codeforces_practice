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

    ll m, n;
    cin >> m >> n;

    string t, s;
    cin >> t >> s;

    if (m > n)
    {
        return 0;
    }

    // t is smaller and s is larger
    // i is for s
    // j is for s and k is for t

    vector<ll> mn_v;
    ll mn_sz = LLONG_MAX;
    for (int i = 0; i + m <= n; i++)
    {
        vector<ll> v;
        for (int j = i, k = 0; j < n && k < m; j++, k++)
        {
            // cout << "Here" << endl;
            if (s[j] != t[k])
            {
                v.push_back(k + 1);
            }
            // cout << j << endl;
        }
        if (mn_sz > v.size())
        {
            mn_v = {};
            copy(v.begin(), v.end(), back_inserter(mn_v));
            mn_sz = v.size();
        }
        // cout << "v is:" << endl;
        // printVec(v);
    }
    cout << mn_sz << endl;
    printVec(mn_v);

    return 0;
}