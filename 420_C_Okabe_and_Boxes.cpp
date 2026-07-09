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

    ll n;
    cin >> n;

    vector<ll> v(n, 0);

    ll size = 0, last_removed = 0, min_ops = 0;
    for (ll i = 0; i < 2 * n; i++)
    {
        string op = "";
        ll num = -1;
        cin >> op;
        if (op == "add")
            cin >> num;
        // if (op == "add")
        // cout << "\n\nOp:" << op << " num:" << num << endl;
        // else
        // {
        // cout << "\n\nOp:" << op << endl;
        // }
        if (op == "add")
        {

            size++;
            v[size - 1] = num;

            // else if (last_op == "remove")
            // {
            //     // if (v[size] != last_removed + 1)
            //     // {
            //     //     min_ops++;
            //     //     sort(v.begin(), v.begin() + size + 1);
            //     // }
            //     if (v[size] != last_removed + 1)
            //     {
            //         isAddDone
            //     }
            // }
            // cout << "In add" << endl;
            // printVec(v);
        }
        else if (op == "remove")
        {
            last_removed++;
            // cout << "\nBefore the sorting process:" << endl;
            // printVec(v);

            if (size == 0)
            {
                continue;
            }

            if (v[size - 1] == last_removed)
            {
                // cout << "\nSorting the actual array\n";
                // min_ops++;
                // sort(v.begin(), v.begin() + size, greater<ll>());
                v[size - 1] = 0;
                size--;
            }
            else
            {
                size = 0;
                min_ops++;
            }
        }
    }

    // printVec(v);
    cout << min_ops << endl;

    return 0;
}