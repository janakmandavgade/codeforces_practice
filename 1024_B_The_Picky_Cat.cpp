#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
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

        // find n/2 + 1 th smallest element
        // if 0 <= n/2 + 1th element then possible else not

        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            ll mth_smallest = (n / 2) + 1;
            if (pq.empty() || pq.size() < mth_smallest)
            {
                pq.push(abs(v[i]));
            }
            else if (pq.size() >= mth_smallest && abs(pq.top()) > abs(v[i]))
            {
                pq.pop();
                pq.push(abs(v[i]));
            }
        }

        // cout << pq.top() << endl;

        if (abs(v[0]) <= pq.top())
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