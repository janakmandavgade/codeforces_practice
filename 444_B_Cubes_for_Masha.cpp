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

bool canMake(int num, vector<unordered_set<ll>> &cubes)
{
    if (num < 10)
    {
        int digit = num;

        for (int cube = 0; cube < cubes.size(); cube++)
        {
            if (cubes[cube].count(digit))
            {
                return true;
            }
        }

        return false;
    }

    int tens = num / 10;
    int ones = num % 10;

    for (int c1 = 0; c1 < cubes.size(); c1++)
    {
        if (!cubes[c1].count(tens))
            continue;

        for (int c2 = 0; c2 < cubes.size(); c2++)
        {
            if (c1 == c2)
                continue;

            if (cubes[c2].count(ones))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

    vector<unordered_set<ll>> v;

    for (int i = 0; i < n; i++)
    {
        unordered_set<ll> st;
        for (int j = 0; j < 6; j++)
        {
            ll val;
            cin >> val;

            st.insert(val);
        }

        v.push_back(st);
    }

    int ans = 0;

    for (int num = 1; num <= 98; num++)
    {
        if (canMake(num, v))
        {
            ans = num;
        }
        else
        {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}