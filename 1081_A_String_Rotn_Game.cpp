#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        
        string s;
        cin>>s;

        s += s;
        int ans = INT_MIN;
        for(int i = 0 ; i + n < 2*n ; i++){
            int cnt = 0;
            int l = i, r = i;
            while(l < i + n && r < i + n){
                while(s[r] == s[l]) r++;
                cnt++;
                l = r;
            }
            ans = max(cnt, ans);
        }

        cout<<ans<<endl;
    }

    return 0;
}