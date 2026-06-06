#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <set>
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
    for (ll i = 0; i < (ll)v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return;
}

struct MultisetSort
{
    bool operator()(const vector<ll> &p1, const vector<ll> &p2) const
    {
        if (p1[0] == p2[0])
            return p1[1] > p2[1];
        return p1[0] > p2[0];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;

    vector<ll> curr(n), disc(n);

    inputVec(curr, n);
    inputVec(disc, n);

    // diff, val of curr, val of disc, idx
    multiset<vector<ll>, MultisetSort> st;

    for (ll i = 0; i < n; i++)
    {
        st.insert({disc[i] - curr[i], curr[i], disc[i], i});
    }

    vector<bool> curr_or_disc(n, 0);

    // cout << "Printing St" << endl;
    // for (auto &it : st)
    // {
    //     cout << "Diff:" << it[0] << " Curr:" << it[1] << " Disc" << it[2] << " idx:" << it[3] << endl;
    // }

    ll cnt = 0;
    for (auto &it : st)
    {
        if (it[0] <= 0)
        {
            if (cnt >= k)
                break;
        }
        cnt++;
        curr_or_disc[it[3]] = 1;
        // cout << it[3] << endl;
    }

    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        ans += ((curr_or_disc[i] == 0) ? disc[i] : curr[i]);
    }

    cout << ans << endl;

    return 0;
}