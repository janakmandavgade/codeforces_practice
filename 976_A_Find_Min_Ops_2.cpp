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

        while(n != 0){
            int rem = n % k;
            n = n/k;
            cnt += rem;
        }

        cout<<cnt<<endl;

    }
    return 0;
}