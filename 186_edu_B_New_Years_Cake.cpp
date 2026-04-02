#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll dark, white;
        cin>>dark>>white;
        
        ll sum_odd = 0, sum_even = 0;
        ll layer_val = 1;
        ll mx_val = max(dark, white);
        ll ans = 0;
        for(ll i = 0 ; i <= 60 ; i++){
            if(i%2 == 0){
                sum_even += layer_val;
            }else{
                sum_odd += layer_val;
            }
            layer_val *= 2;
            if((sum_odd <= dark && sum_even <= white) || (sum_even <= dark && sum_odd <= white)){
                ans++; 
            }else{
                break;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}