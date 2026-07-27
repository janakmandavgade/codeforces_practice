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

bool checkPal(ll num)
{
    string s = to_string(num);
    // bool ans = true;
    for (ll i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        bool found = false;
        ll a, b;
        // ll x = n;
        // ll y = n;
        ll x = n - (n % 12);
        ll y = n % 12;
        while (!found)
        {
            // cout << "X and Y:" << x << " " << y << endl;
            if (x < 0 || y < 0)
            {
                cout << -1 << endl;
                break;
            }
            else if ((checkPal(x) && y % 12 == 0))
            {
                // cout << "Entered in 1" << endl;
                a = x;
                b = y;
                found = true;
                break;
            }
            else if ((x % 12 == 0 && checkPal(y)))
            {
                // cout << "Entered in 2" << endl;
                a = y;
                b = x;
                found = true;
                break;
            }

            // cout << "Found ?:" << found << endl;

            x -= 12;
            y += 12;
        }

        if (found == true)
        {
            // cout << "entered here" << endl;
            cout << a << " " << b << endl;
        }
    }

    return 0;
}