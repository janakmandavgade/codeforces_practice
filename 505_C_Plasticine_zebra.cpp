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

    string s;
    cin >> s;

    s = s + s;
    // cout<<s<<endl;
    // cout << "here" << endl;
    ll n = s.size();
    ll mx_len = INT_MIN;
    // bool yesInside = false;
    for (ll i = 0; i < n; i++)
    {
        ll j = i;
        // bool yesInside = false;
        // string curr = "";
        while (j + 1 < n && s[j] != s[j + 1])
        {
            // cout << j << endl;
            // curr += s[j];
            // yesInside = true;
            j++;
        }
        // cout << curr << endl;
        mx_len = max(mx_len, j - i + 1);

        // if (yesInside)
        // {
        //     i = j - 1;
        //     // yesInside = false;
        // }
        i = j;
    }

    cout << min(mx_len, (ll)s.size() / 2) << endl;

    return 0;
}