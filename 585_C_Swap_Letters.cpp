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

    // so i now have
    string s, t;
    cin >> s;
    cin >> t;

    if (s == t)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        ll ab_cnt = 0, ba_cnt = 0;
        vector<ll> ab_idx, ba_idx;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == t[i])
                continue;
            else
            {
                if (s[i] == 'a')
                {
                    ab_cnt++;
                    ab_idx.push_back(i);
                }
                else
                {
                    ba_cnt++;
                    ba_idx.push_back(i);
                }
            }
            // cout << endl;
        }

        if ((ab_cnt + ba_cnt) % 2 == 1)
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            ll min = ab_cnt / 2 + ba_cnt / 2 + ((ab_cnt % 2 && ba_cnt % 2) ? 2 : 0);
            cout << min << endl;
            for (ll i = 0; i + 1 < ab_cnt; i += 2)
            {
                cout << ab_idx[i] + 1 << " " << ab_idx[i + 1] + 1 << endl;
            }
            for (ll i = 0; i + 1 < ba_cnt; i += 2)
            {
                cout << ba_idx[i] + 1 << " " << ba_idx[i + 1] + 1 << endl;
            }

            if (ab_cnt % 2 && ba_cnt % 2)
            {
                cout << ab_idx[ab_cnt - 1] + 1 << " " << ab_idx[ab_cnt - 1] + 1 << endl;
                cout << ab_idx[ab_cnt - 1] + 1 << " " << ba_idx[ba_cnt - 1] + 1 << endl;
            }
        }
    }

    return 0;
}