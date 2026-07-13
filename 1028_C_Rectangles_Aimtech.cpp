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

    vector<vector<ll>> v;

    vector<ll> pref_lx(n), pref_ly(n), pref_hx(n), pref_hy(n);
    vector<ll> suff_lx(n), suff_ly(n), suff_hx(n), suff_hy(n);

    for (ll i = 0; i < n; i++)
    {
        ll lx, ly, hx, hy;
        cin >> lx >> ly >> hx >> hy;

        v.push_back({lx, ly, hx, hy});
    }

    pref_lx[0] = v[0][0];
    pref_ly[0] = v[0][1];
    pref_hx[0] = v[0][2];
    pref_hy[0] = v[0][3];

    suff_lx[n - 1] = v[n - 1][0];
    suff_ly[n - 1] = v[n - 1][1];
    suff_hx[n - 1] = v[n - 1][2];
    suff_hy[n - 1] = v[n - 1][3];

    for (ll i = 1; i < n; i++)
    {
        pref_lx[i] = max(pref_lx[i - 1], v[i][0]);
        pref_ly[i] = max(pref_ly[i - 1], v[i][1]);
        pref_hx[i] = min(pref_hx[i - 1], v[i][2]);
        pref_hy[i] = min(pref_hy[i - 1], v[i][3]);
    }

    for (ll i = n - 2; i >= 0; i--)
    {
        suff_lx[i] = max(suff_lx[i + 1], v[i][0]);
        suff_ly[i] = max(suff_ly[i + 1], v[i][1]);
        suff_hx[i] = min(suff_hx[i + 1], v[i][2]);
        suff_hy[i] = min(suff_hy[i + 1], v[i][3]);
    }

    for (ll i = 0; i < n; i++)
    {
        ll connected_rect = 0;
        ll lx, ly, hx, hy;
        ll mx_lx = INT_MIN, mn_hx = INT_MAX, mx_ly = INT_MIN, mn_hy = INT_MAX;

        if (i - 1 < 0)
        {
            mx_lx = suff_lx[i + 1];
            mx_ly = suff_ly[i + 1];

            mn_hx = suff_hx[i + 1];
            mn_hy = suff_hy[i + 1];
        }
        else if (i + 1 >= n)
        {
            mx_lx = pref_lx[i - 1];
            mx_ly = pref_ly[i - 1];

            mn_hx = pref_hx[i - 1];
            mn_hy = pref_hy[i - 1];
        }
        else
        {
            mx_lx = max(pref_lx[i - 1], suff_lx[i + 1]);
            mx_ly = max(pref_ly[i - 1], suff_ly[i + 1]);

            mn_hx = min(pref_hx[i - 1], suff_hx[i + 1]);
            mn_hy = min(pref_hy[i - 1], suff_hy[i + 1]);
        }

        if (mx_lx <= mn_hx && mx_ly <= mn_hy)
        {
            cout << mx_lx << " " << mx_ly << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;

    return 0;
}