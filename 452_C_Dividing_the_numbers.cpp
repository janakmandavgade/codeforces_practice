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

    vector<ll> v1;

    ll i = 1, j = n;
    ll sum = n * (n + 1) / 2;

    // cout << "V1 is: " << endl;

    // printVec(v1);
    ll sum_2 = sum / 2;
    for (ll i = n; i >= 1; i--)
    {
        if ((sum_2)-i >= 0)
        {
            v1.push_back(i);
            sum_2 -= i;
        }
    }
    cout << (((sum) % 2 == 0) ? 0 : 1) << endl;
    cout << v1.size() << " ";
    printVec(v1);
    cout << endl;

    return 0;
}