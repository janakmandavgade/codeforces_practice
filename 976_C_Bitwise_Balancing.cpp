#include <bits/stdc++.h>
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
        ll b, c, d;
        cin >> b >> c >> d;
        ll a = 0;
        bool not_possible = false;
        for (int i = 0; i < 64; i++)
        {
            int b_bit = (b >> i) & 1;
            int c_bit = (c >> i) & 1;
            int d_bit = (d >> i) & 1;
            if ((1 | b_bit) - (1 & c_bit) == d_bit)
            {
                // append 1 to a;
                a |= (1LL << i);
            }
            else if ((0 | b_bit) - (0 & c_bit) == d_bit)
            {
                // append 0 to a;
                //  a >> i = 0;
                //  do nothing
                ;
            }
            else
            {
                cout << -1 << endl;
                not_possible = true;
                break;
            }
        }

        if (!not_possible)
        {
            cout << a << endl;
        }
    }

    return 0;
}