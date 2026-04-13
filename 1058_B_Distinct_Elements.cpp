// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// #include <string>
// using namespace std;

// typedef long long int ll;

// void printVec(vector<ll> &v)
// {
//     for (ll i = 0; i < v.size(); i++)
//         cout << v[i] << " ";
//     cout << endl;

//     return;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         ll n;
//         cin >> n;

//         vector<ll> v(n), b;
//         for (auto &it : v)
//             cin >> it;

//         b.push_back(1);

//         if (n == 1)
//         {
//             cout << 1 << endl;
//             continue;
//         }

//         ll i, distinct = 1, val = 1;

//         for(int i = 1 ; i < n ; i++){
//             int diff_val_ans = (i+1) + v[i-1];
//             int same_val_ans = (v[i-1] + 1);

//             // cout<<diff_val_ans<<endl;
//             if(diff_val_ans == v[i]){
//                 val++;
//             }else if(same_val_ans == v[i]){
//                 ;
//             }else{
//                 val--;
//             }

//             b.push_back(val);
//         }

//         printVec(b);
//     }

//     return 0;
// }




#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> b(n);
        for (auto &x : b) cin >> x;
        
        vector<ll> a(n);
        ll nextFresh = 1;
        a[0] = nextFresh++;  // always fresh, b[0] is always 1
        
        for (ll i = 1; i < n; i++) {
            ll diff = b[i] - b[i-1];
            ll x = (i + 1) - diff;  // 1-indexed last occurrence
            
            if (x == 0) {
                // Never appeared before
                a[i] = nextFresh++;
            } else {
                // Copy value from last occurrence (convert to 0-indexed: x-1)
                a[i] = a[x - 1];
            }
        }
        
        for (ll i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n-1];
    }
    return 0;
}