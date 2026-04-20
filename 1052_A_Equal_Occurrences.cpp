#include <iostream>
#include <vector>
// #include <unordered_map>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

typedef long long int ll;

template <typename t1, typename t2>
ostream& operator<<(ostream& os, pair<t1, t2> p){
    os << "{" << p.first << ", " << p.second <<"}";
    return os;
}

template <typename t>
void printVec(vector<t> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return;
}

static bool comp(pair<int,int>& p1, pair<int,int>& p2){
    return p1.first > p2.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        if (n == 0)
        {
            cout << 0 << endl;
            continue;
        }

        vector<int> nums(n), freq(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            freq[nums[i]-1]++;
        }
        
        sort(freq.begin(), freq.end());
        int total_sum = 0;
        total_sum = accumulate(freq.begin(), freq.end(), 0);

        int mn = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            mn = min(mn, (int)(total_sum - (n - i) * (freq[i])));
        }

        cout<<n - mn << endl;
        
    }

    return 0;
}