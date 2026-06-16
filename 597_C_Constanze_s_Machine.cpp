#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

#define MOD 1000000007LL

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

    string s;
    cin >> s;

    vector<ll> fib(s.size() + 2, 0);

    // fib[0] = 0;
    fib[1] = 1;
    for (ll i = 2; i < s.size() + 2; i++)
    {
        fib[i] = (fib[i - 1] % MOD) + (fib[i - 2] % MOD);
    }

    // printVec(fib);

    bool isBroken = false;
    ll sum = 1;
    for (ll i = 0; i < s.size() && !isBroken; i++)
    {
        if (s[i] == 'w' || s[i] == 'm')
        {
            cout << 0 << endl;
            isBroken = true;
            break;
        }

        if (s[i] == 'n' || s[i] == 'u')
        {
            ll j = i;
            char ch = s[i];
            while (j < s.size() && s[j] == ch)
            {
                j++;
            }

            ll len = j - i;
            // cout << len << endl;

            // cout << i << " " << j << endl;
            // cout << (fib[len] % (ll)MOD) << endl;
            sum = (sum * (fib[len + 1] % MOD)) % MOD;
            // cout << sum << endl;
            // if (j >= s.size())
            //     break;
            // if (j == s.size())
            //     break;

            i = --j;
        }
    }

    if (!isBroken)
    {
        cout << ((sum == 0) ? 1 : sum) << endl;
    }

    return 0;
}