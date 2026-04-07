#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
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
        ll a, b, n;
        cin >> a >> b >> n;
        ll cnt = 0;
        ll prev = -1;
        if (a <= b || (double)a / n >= b)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
        // cout<<cnt<<endl;
    }

    return 0;
}