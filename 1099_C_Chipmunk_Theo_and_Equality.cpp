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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> v(n);
        inputVec(v, n);

        // For v[0] values reachable
        unordered_map<ll, ll> c1, c2;
        unordered_set<ll> s;

        ll curr = v[0], steps = 0;

        while (s.count(curr) == 0)
        {
            c1[curr] += steps;
            c2[curr]++;

            s.insert(curr);
            if (curr % 2 == 0)
            {
                curr >>= 1;
            }
            else
            {
                curr++;
            }
            steps++;
        }

        for (ll i = 1; i < n; i++)
        {
            curr = v[i];
            steps = 0;

            s.clear();

            while (s.count(curr) == 0)
            {
                // c1[curr] += steps;
                // c2[curr]++;

                if (c1.count(curr))
                {
                    c1[curr] += steps;
                    c2[curr]++;
                }

                s.insert(curr);
                if (curr % 2 == 0)
                {
                    curr >>= 1;
                }
                else
                {
                    curr++;
                }
                steps++;
            }
        }

        ll ans = LLONG_MAX;
        for (auto &[k, v] : c2)
        {
            if (v == n)
            {
                ans = min(ans, c1[k]);
            }
        }

        cout << ans << endl;
    }
    return 0;
}