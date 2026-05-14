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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    cin >> a >> b;

    // if (b == 0)
    // {
    //     cout << 0 << endl;
    //     return 0;
    // }
    // else if (a == b)
    // {
    //     cout << 1 << endl;
    //     return 0;
    // }
    // cout << "here" << endl;
    // a = a % 10, b = b % 10;

    // if (a > b)
    //     swap(a, b);
    
    if (b - a >= 10)
    {
        cout << 0 << endl;
        return 0;
    }
    
    ll ans = 1;
    for (ll i = a + 1; i <= b; i++)
    {
        ans = (ans * ((i) % 10)) % 10;
        // isEntered = true;
    }

    // cout << 0 % 10 << endl;
    // cout << ((isEntered == true) ? (ans % 10) : 0) << endl;
    cout << ans << endl;

    return 0;
}