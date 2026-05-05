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
        ll n;
        cin >> n;

        vector<ll> v(n);
        inputVec(v, n);

        ll cnt_same_ele = 0;
        ll max_ele = LLONG_MIN;
        for (ll i = 0; i < n; i++)
        {
            max_ele = max(v[i], max_ele);
            if (i != 0 && v[i] == v[i - 1])
            {
                cnt_same_ele++;
            }
        }

        if (cnt_same_ele == n - 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (ll i = 0; i < n; i++)
            {
                if (v[i] == max_ele)
                {
                    cout << "1" << " ";
                }
                else
                {
                    cout << "2" << " ";
                }
            }
            cout<<endl;
        }
    }

    return 0;
}