#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>
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

    ll n;
    cin >> n;

    vector<pair<ll, ll>> v;
    // unordered_set<pair<ll, ll>> st(n);
    pair<ll, ll> prev = {0, 0};
    for (ll i = 0; i < n; i++)
    {
        ll first, second;
        cin >> first;
        cin >> second;

        if (prev.first == first && prev.second == second)
        {
            // cout << "v[i - 1].first:" << v[i - 1].first << " v[i - 1].second:" << v[i - 1].second << endl;
            continue;
        }
        else
        {
            v.push_back({first, second});
        }
        prev = {first, second};
    }

    // printVec(v);
    prev = {0, 0};

    ll cnt = 1;
    for (ll i = 0; i < v.size(); i++)
    {
        // cout << "Prev:" << prev.first << ":" << prev.second << endl;
        // cout << "Curr:" << v[i].first << ":" << v[i].second << endl;

        ll l = max(prev.first, prev.second);
        ll r = min(v[i].first, v[i].second);

        // ✅ FIX: avoid double counting if prev is already a draw
        if (prev.first == prev.second)
            l++;

        if (l <= r)
            cnt += (r - l + 1);

        prev = v[i];
    }

    cout << cnt << endl;

    return 0;
}