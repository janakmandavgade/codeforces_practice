#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
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

    ll n, k, m;
    cin >> n >> k >> m;

    vector<string> ip(n);
    inputVec(ip, n);

    vector<ll> cost(n);
    inputVec(cost, n);

    vector<priority_queue<pair<ll, string>, vector<pair<ll, string>>, greater<pair<ll, string>>>> vpq(k);

    unordered_map<string, ll> mpp;
    for (int i = 0; i < k; i++)
    {
        ll values_in_grp;
        cin >> values_in_grp;

        priority_queue<pair<ll, string>, vector<pair<ll, string>>, greater<pair<ll, string>>> pq;
        for (int j = 0; j < values_in_grp; j++)
        {
            ll idx;
            cin >> idx;

            // cout << "Idx inside loop is:" << idx << endl;
            idx--;
            mpp[ip[idx]] = i;

            pq.push({cost[idx], ip[idx]});
        }

        vpq[i] = pq;
    }

    // for (auto &[k, v] : mpp)
    // {
    //     cout << "Idx:" << k << " grp:" << v << endl;
    // }

    vector<string> message(m);
    ll ans = 0;

    for (ll i = 0; i < m; i++)
    {
        cin >> message[i];

        if (mpp.find(message[i]) != mpp.end())
        {
            // cout << "Inside mpp.find" << endl;
            ll belongs_to_grp = mpp[message[i]];
            ll curr_cost = vpq[belongs_to_grp].top().first;
            ans += curr_cost;
        }
    }

    cout << ans << endl;

    return 0;
}