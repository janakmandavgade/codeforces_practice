#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int cnt_0 = 0, cnt_1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') cnt_0++;
            else             cnt_1++;
        }

        if(cnt_0 == n){
            // Already all zeros
            cout << 0 << "\n";
        } else if(cnt_0 % 2 == 1){
            // cnt_0 is odd → flip all 0 bits
            cout << cnt_0 << "\n";
            for(int i = 0; i < n; i++)
                if(s[i] == '0') cout << i+1 << " ";
            cout << "\n";
        } else if(cnt_1 % 2 == 0){
            // cnt_0 even, cnt_1 even → flip all 1 bits
            cout << cnt_1 << "\n";
            for(int i = 0; i < n; i++)
                if(s[i] == '1') cout << i+1 << " ";
            cout << "\n";
        } else {
            // cnt_0 even, cnt_1 odd → impossible
            cout << -1 << "\n";
        }
    }

    return 0;
}