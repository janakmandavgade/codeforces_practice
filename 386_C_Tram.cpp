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

    ll s, x1, x2, t1, t2, p, d;
    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;

    ll req_d = (x1 < x2 ? 1 : -1);

    ll value = 0;
    ll train_curr_pos = p;
    bool isIgorPicked = false;

    while (!(isIgorPicked == true && train_curr_pos == x2))
    {
        if (train_curr_pos == s || train_curr_pos == 0)
        {
            d = (d == -1 ? 1 : -1);
        }

        if (train_curr_pos == x2 && isIgorPicked)
        {
            break;
        }

        if (train_curr_pos == x1 && !isIgorPicked && req_d == d)
        {
            isIgorPicked = true;
        }

        train_curr_pos += ((d == 1) ? 1 : -1);
        value += t1;
    }

    value = min(value, abs(x2 - x1) * t2);
    cout<<value<<endl;

    return 0;
}