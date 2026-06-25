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

    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    set<char> st;
    for (char ch : s)
        st.insert(ch);

    // check if everything is descending in string
    if (k > n)
    {
        string ans = s;
        while (k != ans.size())
        {
            ans += *st.begin();
        }

        cout << ans << endl;
    }
    else
    {

        // find from back the element that is not largest and store index
        ll idx_ch = -1;

        char largest_char = *(prev(st.end()));
        // cout << "Largest Char:" << largest_char << endl;
        for (ll i = min(n - 1, k - 1); i >= 0; i--)
        {
            // cout << s[i] << endl;
            if (s[i] < largest_char)
            {
                idx_ch = i;
                break;
            }
        }

        // cout << "idx_ch:" << idx_ch << endl;
        string ans;

        for (ll i = 0; i < idx_ch; i++)
        {
            ans += s[i];
        }

        // cout << "Ans before idx_ch:" << ans << endl;

        ans += *(st.upper_bound(s[idx_ch]));

        // cout << "Ans at idx_ch:" << ans << endl;
        // cout << ans << endl;
        for (ll i = 0; i < k - idx_ch - 1; i++)
        {
            ans += *(st.begin());
        }

        // cout << "Ans after idx_ch:" << ans << endl;

        cout << ans << endl;
    }

    return 0;
}