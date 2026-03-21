#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, m, d;
        cin>>n>>m>>d;

        // int cnt = 0;
        // int sum = 0;

        // while(n > 0){
        //     if(d - sum < 0){
        //         cnt++;
        //         sum = 0;
        //         // n--;
        //         // continue;
        //     }
        //     sum+=m;
        //     n--;
        // }

        // cout<<cnt+1<<endl;

        int k = (d/m) + 1;

        int ans = n / k + (n%k != 0 ? 1 : 0);
        cout<<ans<<endl;
        
    }
    return 0;
}