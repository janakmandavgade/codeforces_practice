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
        ll n, k;
        cin >> n >> k;

        vector<ll> v(n);
        inputVec(v, n);

        ll mx = LLONG_MIN, mn = LLONG_MAX, sum = 0;
        ll mx_cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            sum += v[i];
            mx = max(mx, v[i]);
            mn = min(mn, v[i]);
        }

        for(int i = 0 ; i < n ; i++){
            if(mx == v[i]) mx_cnt++;
        }
        mx--;
        if (mx - mn > k || (mx_cnt >= 2 && mx - mn == k))
        {
            cout << "Jerry" << endl;
        }
        else
        {
            if (sum % 2 == 0)
            {
                cout << "Jerry" << endl;
            }
            else
            {
                cout << "Tom" << endl;
            }
        }
    }

    return 0;
}