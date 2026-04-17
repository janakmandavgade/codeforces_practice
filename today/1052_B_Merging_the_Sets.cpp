#include <iostream>
#include <vector>
using namespace std;

// Changed to 1-based indexing for m to match problem constraints 1 to m
bool checkForZeros(vector<int> &freq, int m){
    for(int i = 1 ; i <= m ; i++){
        if(freq[i] == 0) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; // Standard int is fine for counts here
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        
        // Use m + 1 to avoid offset errors with numbers 1..m
        vector<int> freq(m + 1, 0);
        vector<vector<int>> v(n); // Don't use v(n, vector<int>()) + push_back

        for(int i = 0; i < n; i++) {
            int set_sz;
            cin >> set_sz;
            v[i].resize(set_sz);
            for(int j = 0 ; j < set_sz ; j++) {
                cin >> v[i][j];
                freq[v[i][j]]++;
            }
        }

        // 1. Check if it's even possible to cover everything
        if(checkForZeros(freq, m)){
            cout << "NO" << "\n";
            continue;
        }

        // 2. Count how many sets are "removable"
        int removable_sets = 0;
        for(int i = 0 ; i < n ; i++){
            bool canRemove = true;
            for(int val : v[i]){
                // If any element only appears once, this set is essential
                if(freq[val] == 1){
                    canRemove = false;
                    break;
                }
            }
            if(canRemove) removable_sets++;
            
            // Optimization: If we found 2 removable sets, that's 3 ways total
            if(removable_sets >= 2) break; 
        }

        // Way 1: All sets
        // Way 2+: Each removable set creates a unique n-1 way
        if(removable_sets >= 2){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}