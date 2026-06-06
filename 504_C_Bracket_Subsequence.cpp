#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
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

    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    ll open_used = 0, closed_used = 0;
    ll needed = k / 2;

    // cout << s << endl;

    string ans = "";
    for (ll i = 0; i < n; i++)
    {
        // cout << "idx:" << i << " " << open_used << " " << closed_used << endl;
        // cout << open_used << " " << needed << endl;

        // cout << open_used << " < " << needed << " Condition:" << (s[i] == '(') << endl;
        if (open_used < needed && s[i] == '(')
        {
            ans += '(';
            open_used++;
        }

        // cout << closed_used << " < " << needed << " Condition:" << (s[i] == ')') << endl;
        if (closed_used < needed && s[i] == ')')
        {
            ans += ')';
            closed_used++;
        }
        // if (open_used == k / 2 && closed_used == k / 2)
        //     break;

        // cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}