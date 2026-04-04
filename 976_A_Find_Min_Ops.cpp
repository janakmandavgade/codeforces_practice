#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        if(n < k || k == 1){
            cout<<n<<endl;
            continue;
        }
        int cnt = 0;

        vector<int> pow_k;
        int pw = 1;
        pow_k.push_back(pw);
        while(pw*k <= n){
            pw = pw*k;
            pow_k.push_back(pw);
        }
        // for(auto it: pow_k) cout<<it<<" ";
        // cout<<endl;
        int val;
        while(n > 0){
            // int div = n/k;
            int idx = pow_k.size()-1;
            while(pow_k[idx] > n){
                idx--;
            }
            val = pow_k[idx];
            n -= val;
            cnt ++;
        }

        cout<<cnt<<endl;

    }
    return 0;
}