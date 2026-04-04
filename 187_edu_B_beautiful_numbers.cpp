#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int sum = 0;

        vector<int> v;

        for (int i = 0; i < s.size(); i++)
        {
            sum += int(s[i] - '0');
            if (i == 0)
            {
                v.push_back(max(0, int(s[i] - '0') - 1));
            }
            else
            {
                v.push_back(int(s[i] - '0'));
            }
        }

        if (sum <= 9)
        {
            cout << 0 << endl;
            continue;
        }

        sort(v.rbegin(), v.rend());

        for (int i = 0; i < v.size(); i++)
        {
            sum -= v[i];
            if (sum < 10)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }

    return 0;
}