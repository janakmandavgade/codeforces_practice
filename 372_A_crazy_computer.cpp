#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main(){
    ll n, c;
    cin>>n>>c;

    vector<ll> v(n);
    ll cnt = 1;
    for(ll i = 0 ; i < n ; i++){
        cin>>v[i];
        if(i != 0){
            if(v[i] - v[i-1] <= c){
                cnt++;
            }else{
                cnt = 1;
            }
        }
    }

    if(n == 1) {
        cout<<1<<endl;
        return 0;
    }

    cout<<cnt<<endl;
}