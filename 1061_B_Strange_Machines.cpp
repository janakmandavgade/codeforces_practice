#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long int ll;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        bool hasB = false;
        for (char c : s)
            if (c == 'B')
                hasB = true;

        vector<int> v(q);
        for (auto &it : v)
            cin >> it;

        // for(int i = 0 ; i < n ; i++) cout<<v[i] <<" ";
        // cout<<endl;

        int query = 0;
        while (query < q)
        {
            // if(q < 0) break;
            // cout<<query<<endl;
            if (!hasB)
            {
                cout << v[query] << endl;
            }
            else
            {

                int start = v[query];
                // cout<<"Start: " << start<<endl;
                int i = 0;
                while (start > 0)
                {
                    // cout<< "Current Idx: " << i%n <<endl;
                    if (s[i % n] == 'A')
                    {
                        start--;
                    }
                    else
                    {
                        start /= 2;
                    }
                    i++;
                }
                cout << i << endl;
            }
            query++;
        }
    }
}

// BAABBA
// n/2 - 1