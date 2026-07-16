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

int getNum(char ch)
{
    return ch - '0';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        string s;
        cin >> s;

        // cout << getNum('9') << endl;

        vector<int> suff_min(n + 1, 10);

        for (int i = n - 1; i >= 0; i--)
        {
            suff_min[i] = min(suff_min[i + 1], getNum(s[i]));
        }

        // printVec(suff_min);
        bool found = false;
        for (int boundary = 0; boundary <= 9 && !found; boundary++)
        {
            vector<int> c1, c2;
            // int boundary = i;
            string ans = "";
            for (int i = 0; i < n && !found; i++)
            {
                int curr = getNum(s[i]);
                if (curr < boundary)
                {
                    ans.push_back('1');
                    c1.push_back(curr);
                }
                else if (curr > boundary)
                {
                    ans.push_back('2');
                    c2.push_back(curr);
                }
                else
                {
                    int currColor = -1;
                    if (curr > suff_min[i + 1])
                    {
                        currColor = 2;
                        ans.push_back('2');
                        c2.push_back(curr);
                    }
                    else
                    {
                        currColor = 1;
                        ans.push_back('1');
                        c1.push_back(curr);
                    }
                }
            }
            if (!found)
            {
                // check for ascending in c1 and c2;
                bool isc1Ok = true;
                for (int i = 1; i < c1.size() && isc1Ok; i++)
                {
                    int prev = c1[i - 1];
                    int curr = c1[i];
                    if (prev > curr)
                    {
                        isc1Ok = false;
                        break;
                    }
                }

                bool isc2Ok = true;
                for (int i = 1; i < c2.size() && isc2Ok; i++)
                {
                    int prev = c2[i - 1];
                    int curr = c2[i];
                    if (prev > curr)
                    {
                        isc2Ok = false;
                        break;
                    }
                }
                bool boundaryOk = c1.empty() || c2.empty() || c1.back() <= c2[0];
                if (isc1Ok && isc2Ok && boundaryOk)
                {
                    cout << ans << endl;
                    found = true;
                    break;
                }
            }
        }
        if (!found)
            cout << "-" << endl;
    }

    return 0;
}