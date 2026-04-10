#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> p(n); // Changed name to 'p' for permutation
        int a = -1, b = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            if (p[i] == 1)
                a = i;
            if (p[i] == n)
                b = i;
        }

        string s;
        cin >> s;

        // The logic from your image:
        // Check if the ends or the specific positions of 1 and N are "locked" (1)
        if (s[0] == '1' || s[n - 1] == '1' || s[a] == '1' || s[b] == '1')
        {
            cout << -1 << endl;
        }
        else
        {
            // Convert to 1-based indexing for the output
            int pos1 = a + 1;
            int posN = b + 1;

            cout << 5 << endl;
            // Use a different name than 'v' to avoid conflict
            vector<pair<int, int>> ans = {
                {1, pos1},
                {1, posN},
                {pos1, n},
                {posN, n},
                {min(pos1, posN), max(pos1, posN)}};

            for (auto &it : ans)
            {
                cout << it.first << " " << it.second << "\n";
            }
        }
    }

    return 0;
}