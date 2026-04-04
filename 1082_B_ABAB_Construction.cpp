#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (n % 2 != 0) {
        // Condition 1: s[0] must be 'a' (or '?')
        if (s[0] == 'b') {
            cout << "NO" << endl;
            return;
        }
        // Condition 2: Pairs starting from index 1 must be different
        for (int i = 1; i + 1 < n; i += 2) {
            if (s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]) {
                cout << "NO" << endl;
                return;
            }
        }
    } else {
        // Condition: Pairs starting from index 0 must be different
        for (int i = 0; i + 1 < n; i += 2) {
            if (s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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