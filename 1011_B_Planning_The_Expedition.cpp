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

ll people_eating_in_days(ll days, vector<ll> &v)
{
    ll sum = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        sum += (v[i] / days);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, packages;
    cin >> n >> packages;

    if (n > packages)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> v(packages), freq(101, 0);
    ll h = LLONG_MIN;
    for (ll i = 0; i < packages; i++)
    {
        cin >> v[i];
        freq[v[i]]++;
        h = max(freq[v[i]], h);
    }

    ll l = 1;
    // cout << ((2 + 2) >> 1) << endl;
    // check if l < h or l <= h
    while (l < h)
    {
        ll days = (l + h + 1) >> 1;
        // if(mid < key)
        // else (mid >= key)
        ll people = people_eating_in_days(days, freq);
        if (people >= n)
        {
            l = days;
        }
        else
        {
            h = days - 1;
        }

        // cout << "Low: " << l << " " << "high: " << h << " people:" << people << endl;
    }

    cout << h << endl;

    return 0;
}