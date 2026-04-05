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
    int t;
    cin>>t;
    while(t--){
        ll n, a;
        cin>>n>>a;

        vector<ll> v(n);
        for(ll i = 0 ; i < n ; i++) cin>>v[i];

        sort(v.begin(), v.end());

        ll mn  = LLONG_MAX;
        int l = 0, g = 0;
        for(int i = 0 ; i < n ; i++){
            if(v[i] > a){
                g++;
            }else if(v[i] < a){
                l++;
            }
        }

        // cout<<mn<<endl;

        if(g < l){
            cout<<a - 1<<endl;
        }else{
            cout<<a + 1<<endl;
        }
        

    }

    return 0;
}