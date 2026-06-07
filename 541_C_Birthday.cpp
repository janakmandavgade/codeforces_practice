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
    ll n;
    cin >> n;

    vector<ll> v(n);
    inputVec(v, n);

    sort(v.begin(), v.end());

    vector<ll> ans;
    for (ll i = 0; i < n; i += 2)
    {
        ans.push_back(v[i]);
    }
    if (n % 2 == 1)
    {
        for (ll i = n - 2; i >= 0; i -= 2)
        {
            ans.push_back(v[i]);
        }
    }
    else
    {
        for (ll i = n - 1; i >= 0; i -= 2)
        {
            ans.push_back(v[i]);
        }
    }

    printVec(ans);
    return 0;
}