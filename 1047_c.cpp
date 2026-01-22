#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        // int n;
        // cin>>n;
        ll a, b;
        cin>>b>>a;

        // ll mx = -1;

        // for(int k = 1 ; k <= b/2 ; k++){
        //     if(b%k == 0){
        //         ll val = ((a * k) + (b / k));
        //         if(val % 2 == 0) mx = max(val, mx);
        //     }
        // }

        // if(((a * b) + (b / b)) % 2 == 0)
        //     mx = max(((a * b) + (b / b)), mx);

        // cout<<mx<<endl;
        ll sol = -1; 
        if ((a + b) & 1 == 0) sol = a + b;
        if (a % 2 == 1 && b % 2 == 1) sol = max(sol, a * b + 1);
        else if (a % 2 == 0 && (a % 4 == 0 || b % 2 == 0)) sol = max(sol, 2 + ((a * b) / 2));

        cout<<sol<<endl;
    }
}