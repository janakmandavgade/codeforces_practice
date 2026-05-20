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

    string s;
    cin >> s;

    int n = s.size();

    int r = 0, g = 0, y = 0, b = 0;
    int rc = -1, gc = -1, yc = -1, bc = -1;
    for (int i = 0; i < n; i += 4)
    {
        for (int j = i; j < i + 4; j++)
        {
            if (s[j] == 'R')
                rc = (j + 1) % 4;
            else if (s[j] == 'B')
                bc = (j + 1) % 4;
            else if (s[j] == 'Y')
                yc = (j + 1) % 4;
            else if (s[j] == 'G')
                gc = (j + 1) % 4;
        }
    }

    for (int i = 0; i < n; i += 4)
    {
        for (int j = i; j < i + 4; j++)
        {
            if (s[j] == '!')
            {
                if ((j + 1) % 4 == rc)
                    r++;
                else if ((j + 1) % 4 == bc)
                    b++;
                else if ((j + 1) % 4 == gc)
                    g++;
                else if ((j + 1) % 4 == yc)
                    y++;
            }
        }
    }

    // printVec(v);
    cout << r << " " << b << " " << y << " " << g << endl;

    return 0;
}