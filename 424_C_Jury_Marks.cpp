#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
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

    int k, n;
    cin >> k >> n;

    vector<int> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> pref(k);
    set<int> prefixSet;

    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
        pref[i] = sum;
        prefixSet.insert(sum);
    }

    set<int> possibleInitialScores;

    for (int i = 0; i < k; i++)
    {
        int x = b[0] - pref[i];

        bool ok = true;

        for (int j = 0; j < n; j++)
        {
            int neededPrefix = b[j] - x;

            if (prefixSet.find(neededPrefix) == prefixSet.end())
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            possibleInitialScores.insert(x);
        }
    }

    cout << possibleInitialScores.size() << endl;

    return 0;
}