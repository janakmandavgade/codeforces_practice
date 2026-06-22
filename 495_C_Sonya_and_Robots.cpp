#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
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

    ll n;
    cin >> n;

    vector<ll> v(n);
    inputVec(v, n);

    unordered_map<ll, ll> unq_nums;
    vector<ll> unq_vec(n);

    // cout << "Here 1" << endl;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (unq_nums.count(v[i]) == 0)
        {
            unq_nums[v[i]]++;
        }
        unq_vec[i] = unq_nums.size();
    }

    // printVec(unq_vec);
    // cout << "Here 2" << endl;

    ll ways = 0;
    unordered_map<ll, ll> isDone;
    for (int i = 0; i < n - 1; i++)
    {
        if (isDone.count(v[i]) == 0)
        {
            ways += unq_vec[i + 1];
            isDone[v[i]]++;
        }
    }

    cout << ways << endl;
    // for (auto it : st)
    // {
    //     cout << it.first << "::" << it.second << endl;
    // }
    return 0;
}