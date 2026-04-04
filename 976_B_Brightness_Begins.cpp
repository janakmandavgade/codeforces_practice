#include <bits/stdc++.h>
using namespace std;

int calculate_on_bulbs(int n){

    int sq = sqrt(n);

    // while(sq * sq > n) sq--;
    while((sq+1) * (sq+1) <= n) sq++;
    while(sq * sq > n) sq--;
    return n - sq;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int k; cin>>k;
        int l = k, h = 2*k;

        // cout<<calculate_on_bulbs(1)<<endl;
        // cout<<calculate_on_bulbs(2)<<endl;
        // cout<<calculate_on_bulbs(3)<<endl;
        // cout<<calculate_on_bulbs(4)<<endl;
        // cout<<calculate_on_bulbs(5)<<endl;
        // cout<<calculate_on_bulbs(6)<<endl;

        while(l < h){
            int mid = (l + h) >> 1;
            if(calculate_on_bulbs(mid) < k){
                l = mid + 1;
            }else if(calculate_on_bulbs(mid) >= k){
                h = mid;
            }
        }
        cout<<h<<endl;
    }
    
            
    return 0;
}