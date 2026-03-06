// #include <bits/stdc++.h>
// using namespace std;

// typedef long long int ll;

// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll cnt, flip, left;
//         cin>>cnt>>flip>>left;
        
//         if(left < flip){
//             ll ans = max(0LL, cnt-left);
//             cout<<ans<<endl;
//         }else{
//             ll sand_rem = min(cnt, flip);
//             ll time_elasped = left % flip;
//             ll ans = max(0LL, sand_rem - time_elasped);  
//             cout<<ans<<endl;
//         }

        
//     }
//     return 0;
// }
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    ll s, k, m;
    if (!(cin >> s >> k >> m)) return;

    // n is the number of flips that have occurred
    ll n = m / k;
    ll sand_in_top;

    if (n % 2 == 0) {
        // Even number of flips (0, 2, 4...)
        // The top bulb contains the full original amount
        sand_in_top = s;
    } else {
        // Odd number of flips (1, 3, 5...)
        // The top bulb contains only what fell during the first k-minute window
        sand_in_top = min(s, k);
    }

    ll time_since_last_flip = m % k;
    
    // Remaining sand is what was in the top minus what fell since the last flip
    ll ans = max(0LL, sand_in_top - time_since_last_flip);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}