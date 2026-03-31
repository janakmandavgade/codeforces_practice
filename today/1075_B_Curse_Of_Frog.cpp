#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

static bool comp(vector<ll>& p, vector<ll>& q){
    ll a1 = p[0], b1 = p[1], c1 = p[2];
    ll a2 = q[0], b2 = q[1], c2 = q[2];
    if(((a1*b1) - c1) == ((a2*b2)- c2)) return a1 > a2;
    return ((a1*b1) - c1) > ((a2*b2)- c2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n, x;;
        cin>>n>>x;
        
        vector<vector<ll>> v(n, vector<ll>(3));

        for(ll i = 0 ; i < n ; i++){
            ll a, b, c;
            cin>>a>>b>>c;
            v[i] = {a, b, c};
        }

        sort(v.begin(), v.end(), comp);

        ll cnt = 0;
        ll sum = 0;
        ll i = 0;
        while(sum < x){
            ll a = v[0][0], b = v[0][1], c = v[0][2]; 
            sum += a;
            if(sum >= x){
                break;
            }
            if((b * cnt) + 1 == i){
                cnt++;
                sum -= c;    
            }
            i++;
        }

        cout<<cnt*v[0][2]<<endl;
    }

    return 0;
}