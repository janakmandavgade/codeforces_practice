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

bool heightFeasible(ll knifeHeight, vector<ll> &v, ll n)
{
    ll heightAvailable = 0;
    for (ll i = 0; i < n; i++)
    {
        if (knifeHeight <= v[i])
        {
            heightAvailable += v[i] - knifeHeight;
        }
        else
        {
            if (heightAvailable + v[i] >= knifeHeight)
            {
                heightAvailable -= (knifeHeight - v[i]);
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

ll calculate(ll mn, ll mx, ll n, vector<ll> &v)
{
    // how to find upper bound when a function is involved ?

    ll l = 0, h = mx;

    while (l < h)
    {
        ll mid = l + (h - l + 1) / 2;

        if (heightFeasible(mid, v, n))
        {
            l = mid;
        }
        else
        {
            h = mid - 1;
        }
    }

    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> v(n);
        inputVec(v, n);

        ll psum = 0, ans = LLONG_MAX;  
        for (ll i = 0; i < n; i++)
        {
            psum += v[i];
            ans = min(psum/(i+1), ans);
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}