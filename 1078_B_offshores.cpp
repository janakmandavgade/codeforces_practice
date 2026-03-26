#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n,x,y;
        cin>>n>>x>>y;

        vector<int> v(n);

        int tot_transactions = 0;
        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
            tot_transactions += (v[i]/x);
        }
        // cout<<tot_transactions<<endl;
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            int val = v[i] + ((tot_transactions - (v[i]/x)) * y);
            // cout<<val<<endl;
            ans = max(ans, val);
        }

        cout<<ans<<endl;
    }

    return 0;
}