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
        cout << i << ":" << v[i] << " ";
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

    vector<string> v(n);
    inputVec(v, n);

    vector<string> findv(n);
    for (int i = 0; i < n; i++)
    {
        findv[i] = (v[i] + v[i]);
    }

    // printVec(findv);

    ll final_ans = LLONG_MAX;
    // for every string s
    for (int i = 0; i < n; i++)
    {
        // for every string s+s we will get
        string s = v[i];
        ll ans = 0;
        for (int j = 0; j < n; j++)
        {

            // find s in t
            string t = findv[j];
            ll start_idx = -1;

            if (t.find(s) != string::npos)
            {
                start_idx = t.find(s);
            }
            else
            {
                cout << -1 << endl;
                return 0;
            }
            ans += start_idx;
        }
        final_ans = min(ans, final_ans);
    }

    cout << final_ans << endl;

    return 0;
}