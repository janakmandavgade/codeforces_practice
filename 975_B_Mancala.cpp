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

    ll n = 14;
    vector<ll> v(n, 0);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // ll score = LLONG_MIN;
    // for (ll i = 0; i < n; i++)
    // {
    //     if (v[i] > 0)
    //     {
    //         vector<ll> tmp = v;
    //         tmp[i] = 0;
    //         for (ll j = 1; j <= v[i]; j++)
    //         {
    //             ll idx = (i + j) % n;
    //             tmp[idx]++;
    //         }
    //         // cout << "For value:" << v[i] << endl;
    //         // printVec(tmp);

    //         ll ans = 0;
    //         for (ll j = 0; j < n; j++)
    //         {
    //             if (tmp[j] % 2 == 0)
    //             {
    //                 ans += tmp[j];
    //             }
    //         }
    //         score = max(score, ans);
    //     }
    // }

    // cout << score << endl;

    ll score = LLONG_MIN;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            vector<ll> tmp = v;
            ll full_rounds = v[i] / 14;
            ll remaining_stones = v[i] % 14;
            tmp[i] = 0;

            // add v[i]/14 to everyone
            for (ll j = 0; j < n; j++)
            {
                tmp[j] += full_rounds;
            }

            // for remaining stones
            for (ll j = 1; j <= remaining_stones; j++)
            {
                ll idx = (i + j) % n;
                tmp[idx]++;
            }

            // cout << "For value:" << v[i] << endl;
            // printVec(tmp);

            ll ans = 0;
            for (ll j = 0; j < n; j++)
            {
                if (tmp[j] % 2 == 0)
                {
                    ans += tmp[j];
                }
            }
            score = max(score, ans);
        }
    }

    cout << score << endl;

    return 0;
}