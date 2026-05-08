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

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n, ce, flr;
//         cin >> n >> ce >> flr;

//         ll ce_ops = ce, flr_ops = flr, mn_val = n;

//         // For min
//         while (mn_val != 0 && ce_ops && flr_ops)
//         {
//             if (mn_val % 2LL == 1LL)
//             {
//                 flr_ops--;
//                 mn_val = mn_val / 2LL;
//             }
//             else
//             {
//                 ce_ops--;
//                 mn_val = mn_val / 2LL;
//             }
//             cout << mn_val << " " << flr_ops << " " << ce_ops << endl;
//         }

//         while (mn_val != 0LL && mn_val != 1LL && ce_ops)
//         {
//             mn_val = (mn_val + 1LL) / 2LL;
//             ce--;
//         }

//         // cout << mn_val << " " << flr_ops << " " << ce_ops << endl;

//         while (mn_val != 0LL && flr_ops)
//         {
//             mn_val = (mn_val) / 2LL;
//             flr_ops--;
//         }

//         // cout << mn_val << " " << flr_ops << " " << ce_ops << endl;

//         // for max
//         while (n != 0LL && ce && flr)
//         {
//             if (n % 2LL == 1LL)
//             {
//                 ce--;
//                 n = (n + 1LL) / 2LL;
//             }
//             else
//             {
//                 flr--;
//                 n = n / 2LL;
//             }
//         }

//         // cout << n << " " << ce << " " << flr << endl;

//         while (n != 0 && n != 1 && ce)
//         {
//             n = (n + 1LL) / 2LL;
//             ce--;
//         }

//         // cout << n << " " << ce << " " << flr << endl;

//         while (n != 0LL && flr)
//         {
//             n = (n) / 2LL;
//             flr--;
//         }

//         // cout << n << " " << ce << " " << flr << endl;
//         // cout << mn_val << " " << n << endl;
//     }

//     return 0;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        ll n, ce_init, flr_init;
        cin >> n >> flr_init >> ce_init;

        // --- MINIMUM VALUE CALCULATION ---
        ll mn_val = n, c_ops = ce_init, f_ops = flr_init;
        while (mn_val > 0 && c_ops > 0 && f_ops > 0)
        {
            if (mn_val % 2 != 0)
            {
                f_ops--;
                mn_val /= 2;
            }
            else
            {
                c_ops--;
                mn_val /= 2;
            }
        }
        while (mn_val > 1 && c_ops > 0)
        {
            mn_val = (mn_val + 1) / 2;
            c_ops--;
        }
        while (mn_val > 0 && f_ops > 0)
        {
            mn_val /= 2;
            f_ops--;
        }

        // --- MAXIMUM VALUE CALCULATION ---
        ll mx_val = n, c_max = ce_init, f_max = flr_init;
        while (mx_val > 0 && c_max > 0 && f_max > 0)
        {
            if (mx_val % 2 != 0)
            {
                c_max--;
                mx_val = (mx_val + 1) / 2;
            }
            else
            {
                f_max--;
                mx_val /= 2;
            }
        }
        while (mx_val > 1 && c_max > 0)
        {
            mx_val = (mx_val + 1) / 2;
            c_max--;
        }
        while (mx_val > 0 && f_max > 0)
        {
            mx_val /= 2;
            f_max--;
        }

        cout << mn_val << " " << mx_val << "\n"; // Use \n, not endl
    }
    return 0;
}