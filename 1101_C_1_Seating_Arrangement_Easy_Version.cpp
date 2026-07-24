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

// int recur(int i, int n, int opened, int seated, int totTables, int numSeats, string &s, vector<vector<vector<int>>> &dp)
// {

//     // if reached end
//     if (i == n)
//     {
//         return 0;
//     }

//     // if full
//     if (seated == (totTables * numSeats))
//     {
//         return 0;
//     }

//     if (dp[i][opened][seated] != -1)
//     {
//         return dp[i][opened][seated];
//     }

//     int mx = INT_MIN;
//     if (s[i] == 'E')
//     {

//         if (opened * numSeats > seated)
//         {
//             mx = max(mx, 1 + recur(i + 1, n, opened, seated + 1, totTables, numSeats, s, dp));
//         }
//     }
//     else if (s[i] == 'A')
//     {
//         // either will sit at empty or opened
//         // Will sit at empty
//         if (opened < totTables)
//         {
//             mx = max(mx, 1 + recur(i + 1, n, opened + 1, seated + 1, totTables, numSeats, s, dp));
//         }
//         // will sit at opened
//         if (opened * numSeats > seated)
//         {
//             mx = max(mx, 1 + recur(i + 1, n, opened, seated + 1, totTables, numSeats, s, dp));
//         }
//     }
//     else if (s[i] == 'I')
//     {
//         // opened will get increased by 1 always.
//         // emptyTable
//         if (opened < totTables)
//         {
//             mx = max(mx, 1 + recur(i + 1, n, opened + 1, seated + 1, totTables, numSeats, s, dp));
//         }
//     }

//     // will not sit at all
//     mx = max(mx, recur(i + 1, n, opened, seated, totTables, numSeats, s, dp));

//     return dp[i][opened][seated] = mx;
// }
int ans = 0;

void recur(int i, int n, int opened, int seated, int totTables, int numSeats, string &s, vector<vector<int>> &dp)
{

    ans = max(ans, seated);

    if (i == n)
        return;

    // even if all remaining sit, answer cannot improve20
    if (seated + (n - i) <= ans)
        return;

    if (seated == totTables * numSeats)
        return;

    if (dp[i][opened] >= seated)
    {
        return;
    }

    dp[i][opened] = seated;

    int mx = INT_MIN;

    if (s[i] == 'E')
    {
        // if already opened
        if (opened * numSeats > seated)
        {
            recur(i + 1, n, opened, seated + 1, totTables, numSeats, s, dp);
        }
    }
    else if (s[i] == 'A')
    {
        // either will sit at empty or opened
        // Will sit at empty
        if (opened < totTables)
        {
            recur(i + 1, n, opened + 1, seated + 1, totTables, numSeats, s, dp);
        }
        // will sit at opened
        if (opened * numSeats > seated)
        {
            recur(i + 1, n, opened, seated + 1, totTables, numSeats, s, dp);
        }
    }
    else if (s[i] == 'I')
    {
        // opened will get increased by 1 always.
        // emptyTable
        if (opened < totTables)
        {
            recur(i + 1, n, opened + 1, seated + 1, totTables, numSeats, s, dp);
        }
    }

    // will not sit at all
    recur(i + 1, n, opened, seated, totTables, numSeats, s, dp);

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
        ans = 0;
        ll n, numTables, numSeats;
        cin >> n >> numTables >> numSeats;

        string s;
        cin >> s;

        vector<vector<int>> dp(n + 1, vector<int>(numTables + 1, -1));

        numTables = min(numTables, n);

        recur(0, n, 0, 0, numTables, numSeats, s, dp);
        cout << ans << endl;
    }

    return 0;
}