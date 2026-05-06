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
        ll x, y, a;
        cin >> x >> y >> a;

        // a *= 5;

        // ll curr = 0;
        // bool is_x_turn = true;
        // bool x_won = false;
        // while (true)
        // {
        //     if (is_x_turn && curr + x > a)
        //     {
        //         x_won = true;
        //         break;
        //     }

        //     else if (!is_x_turn && curr + y > a)
        //     {
        //         x_won = false;
        //         break;
        //     }

        //     else if (is_x_turn)
        //     {
        //         curr += x;
        //     }
        //     else
        //     {
        //         curr += y;
        //     }
        //     is_x_turn = !is_x_turn;
        //     // cout << curr << endl;
        // }

        // if (x_won)
        // {
        //     cout << "NO" << endl;
        // }
        // else
        // {
        //     cout << "YES" << endl;
        // }

        // 2 + 1 == 3 so 4%3 = 1
        // is it smaller than x ? yes, then print NO
        // 1 + 2 == 3 so 4 % 3 = 1
        // is 1 smaller than x no so y will win.

        a = a % (x + y);

        if (a >= x)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}