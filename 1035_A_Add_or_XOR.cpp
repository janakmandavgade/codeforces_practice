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
        ll a, b, x, y;
        cin >> a >> b >> x >> y;

        // vector<ll> v(n);
        // inputVec(v, n);
        ll cost = 0;
        if (a > b)
        {
            while (a != b)
            {
                if ((a & 1))
                {
                    cost += y;
                    a ^= 1;
                }
                else
                {
                    break;
                }
            }

            if (a != b)
                cout << -1 << endl;
            else
            {
                cout << cost << endl;
            }
        }
        else if (a == b)
            cout << 0 << endl;
        else
        {
            while (a != b)
            {
                // last bit is not set
                if (!(a & 1) && y <= x)
                {
                    cost += y;
                    a ^= 1;
                }
                else
                {
                    cost += x;
                    a++;
                }
                // cout<<"Cost in loop: " << cost <<endl;
            }
            cout << cost << endl;
        }
    }

    return 0;
}