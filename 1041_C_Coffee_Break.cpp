#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
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

    ll n, m, d;
    cin >> n >> m >> d;

    // vector<pair<ll, ll>> v(n);
    set<pair<ll, ll>> st;

    for (ll i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        st.insert(make_pair(tmp, i));
    }

    // ll i = 1, j = n;
    ll curr_day = 0;

    vector<ll> days(n, -1);

    while (!st.empty())
    {
        curr_day++;
        auto it = st.begin();
        ll last_day = it->first;
        days[it->second] = curr_day;
        st.erase(it);

        while (true)
        {
            auto next_smallest = st.lower_bound({last_day + d + 1, -1});
            if (next_smallest == st.end())
                break;

            days[next_smallest->second] = curr_day;
            last_day = next_smallest->first;
            st.erase(next_smallest);
        }
    }

    // cout << "Final i and j" << i << " " << j << endl;
    cout << curr_day << endl;
    // printVec(days);
    for (int i = 0; i < n; i++)
    {
        cout << days[i] << " ";
    }
    cout << endl;

    return 0;
}