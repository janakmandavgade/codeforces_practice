#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <stack>
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
        // ll n;
        // cin>>n;

        string s;
        cin >> s;

        stack<char> st;
        st.push(s[0]);
        int cnt = 0;
        for (int i = 1; i < s.size(); i++)
        {
            bool popped = false;
            // cout << st.top() << " ::::: " << s[i] << endl;
            if (!st.empty() && st.top() == '(' && s[i] == ')')
            {
                popped = true;
                st.pop();
            }

            // if (st.empty())
            //     cnt++;

            if (!st.empty() && st.top() == ')' && s[i] == '(')
            {
                popped = true;
                st.pop();
            }

            if (st.empty())
                cnt++;

            if (!popped)
                st.push(s[i]);

            // cout << cnt << endl;
        }

        if (cnt == 0 || cnt == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}