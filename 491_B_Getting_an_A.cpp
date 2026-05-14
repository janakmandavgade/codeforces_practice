#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
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

double round_cust(double x)
{
    // if (x - (x / INT_MAX) >= 0.5)
    // {
    //     return x + 1;
    // }

    // return x;

    //
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

    vector<ll> v(n);

    inputVec(v, n);
    double avg = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        avg += v[i];
    }

    avg /= (n * 1.00);
    ll cnt = 0;

    sort(v.begin(), v.end());
    // printVec(v);

    for (ll i = 0; i < n; i++)
    {
        ll rounded_val = llround(avg);
        // cout << "Avg before: " << avg << endl;
        // cout << "rounded_val:" << rounded_val << endl;
        if (rounded_val == 5LL || abs(avg - 4.5) < 1e-9)
        {
            break;
        }

        avg += (5 - v[i]) / (n * 1.00);
        // cout << avg << endl;
        // cout << cnt << endl;
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}