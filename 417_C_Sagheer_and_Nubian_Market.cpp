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

ll calc_cost(ll k, vector<ll> &v)
{
    ll sum = 0;
    vector<ll> curr_cost;
    for (ll i = 1; i <= v.size(); i++)
    {
        curr_cost.push_back((v[i - 1] + (i * k)));
    }
    sort(curr_cost.begin(), curr_cost.end());

    for (ll i = 0; i < k; i++)
    {
        sum += curr_cost[i];
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, tc;
    cin >> n >> tc;

    vector<ll> v(n);
    inputVec(v, n);

    // sort(v.begin(), v.end());

    ll l = 0, h = n;

    ll ans_cost = 0;
    while (l < h)
    {
        ll mid = (l + h + 1) >> 1;
        ans_cost = calc_cost(mid, v);
        if (ans_cost <= tc)
        {
            l = mid;
        }
        else
        {
            h = mid - 1;
        }
    }

    cout << l << " " << calc_cost(l, v) << endl;

    return 0;
}