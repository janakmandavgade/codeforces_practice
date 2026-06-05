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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, f;
    cin >> t >> f;

    priority_queue<pair<ll, pair<ll, ll>>> pq;
    for (ll i = 0; i < t; i++)
    {
        ll k, l;
        cin >> k >> l;

        pq.push({min(2 * k, l) - min(k, l), {k, l}});
    }

    ll ans = 0;
    for (ll i = 0; i < f; i++)
    {
        ll val = min(2 * pq.top().second.first, pq.top().second.second);
        ans += val;
        pq.pop();
    }

    while (!pq.empty())
    {
        ans += min(pq.top().second.first, pq.top().second.second);
        pq.pop();
    }

    cout << ans << endl;

    return 0;
}