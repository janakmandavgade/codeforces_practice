#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;

        vector<ll> v(n);
        unordered_set<ll> st;
        inputVec(v, n);

        sort(v.begin(), v.end(), greater<ll>());
        ll factor = 0;
        // printVec(v);
        for (int i = 0; i < n; i++)
        {
            if (v[i] * (1LL << factor) <= c)
            {
                factor++;
            }
            // printVec(v);
        }

        // int i = 0;
        int ans = n - factor;

        cout << ans << endl;
    }

    return 0;
}