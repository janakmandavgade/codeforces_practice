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

    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    inputVec(v, n);

    ll odds = 0, evens = 0;
    multiset<ll> m;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] % 2)
        {
            odds++;
        }
        else
        {
            evens++;
        }

        if (odds != 0 && evens != 0 && odds == evens && i + 1 < n)
        {
            m.insert(abs(v[i] - v[i + 1]));
        }
    }

    ll cuts = 0;
    for (auto it : m)
    {
        if (k >= it)
        {
            cuts++;
            k -= it;
        }
        else
        {
            break;
        }
    }

    cout << cuts << endl;

    return 0;
}