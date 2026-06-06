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

    ll n;
    cin >> n;

    vector<ll> a(n), b(n);
    inputVec(a, n);
    inputVec(b, n);

    // vector<ll> freq(n + 1, 0);
    unordered_map<ll, ll> mpp;

    vector<ll> ans(n, -1);
    vector<ll> rem_idx;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            mpp[a[i]]++;
            ans[i] = a[i];
        }
        else
        {
            rem_idx.push_back(i);
        }
    }

    vector<ll> missing;

    for (ll i = 1; i <= n; i++)
    {
        if (mpp.count(i) <= 0)
        {
            missing.push_back(i);
        }
    }

    if (rem_idx.size() == 1)
    {
        ans[rem_idx[0]] = missing[0];
    }

    else if (rem_idx.size() == 2)
    {

        ans[rem_idx[0]] = missing[0], ans[rem_idx[1]] = missing[1];

        ll mismatch_a = 0, mismatch_b = 0;
        for (ll i = 0; i < n; i++)
        {
            if (ans[i] != a[i])
            {
                mismatch_a++;
            }
            if (ans[i] != b[i])
            {
                mismatch_b++;
            }
        }

        if (mismatch_a > 1 || mismatch_b > 1)
        {
            ans[rem_idx[0]] = missing[1], ans[rem_idx[1]] = missing[0];
        }
    }

    printVec(ans);

    return 0;
}