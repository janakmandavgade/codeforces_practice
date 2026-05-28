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
    ll n;
    cin >> n;

    vector<ll> v(n);
    inputVec(v, n);

    vector<ll> yr = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                     31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                     31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                     31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                     31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                     31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                     31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                     31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // i should always be the greater one
    // j should always be the smaller one

    // i will either go into yr or v depending on whichever is smaller
    // in this case i will be yr and j will be v;

    for (ll i = 0; i < yr.size(); i++)
    {
        if (yr[i] == v[0])
        {
            ll j = 0;
            while (j < v.size() && i + j < yr.size() && v[j] == yr[i + j])
            {
                // i++;
                j++;
            }
            // cout << i << " " << j << endl;
            if (j >= v.size())
            {
                cout << "Yes" << endl;
                return 0;
            }
            // i--;
        }
    }

    cout << "No" << endl;

    return 0;
}