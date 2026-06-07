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

    string s;
    cin >> s;

    ll k;
    cin >> k;

    ll n = 0;
    ll cnt_candies = 0;
    ll cnt_snowflakes = 0;

    string ans = "";

    ll sz = s.size();

    for (ll i = 0; i < sz; i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            n++;
        }
        else if (s[i] == '*')
        {
            cnt_snowflakes++;
        }
        else if (s[i] == '?')
        {
            cnt_candies++;
        }
    }

    for (ll i = 0; i < sz; i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            ans.push_back(s[i]);
        }
        else if (n > k && (s[i] == '?' || s[i] == '*'))
        {
            ans.pop_back();
            n--;
        }
        else if (n < k && s[i] == '*')
        {
            while (n != k)
            {
                ans.push_back(s[i - 1]);
                n++;
            }
        }
        // cout << n << " " << k << endl;
        // cout << ans << endl;
    }

    cout << ((ans.size() != k) ? "Impossible" : ans) << endl;

    return 0;
}