#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
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
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        string t;
        cin >> t;

        ll i = 0, j = 0;
        bool isOk = true;
        while (i < s.size() && j < t.size() && isOk)
        {
            if (s[i] != t[j])
            {
                cout << "NO" << endl;
                isOk = false;
                break;
            }

            ll c_s = 0, c_t = 0;
            while (i + 1 < s.size() && s[i] == s[i + 1])
            {
                c_s++;
                i++;
            }

            while (j + 1 < t.size() && t[j] == t[j + 1])
            {
                c_t++;
                j++;
            }

            if (c_s > c_t)
            {
                cout << "NO" << endl;
                isOk = false;
                break;
            }
            i++, j++;
        }
        // cout<<"Here"<<endl;
        // while (j < t.size())
        // {
        //     if (j < t.size() && s[i - 1] == t[j])
        //     {
        //         j++;
        //     }
        // }

        // cout << "I:" << i << " " << "J:" << j << endl;
        if (((i != s.size()) || (j != t.size())) && isOk)
        {
            cout << "NO" << endl;
        }
        else if (isOk)
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
