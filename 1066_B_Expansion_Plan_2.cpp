#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

void printVec(vector<ll> &v){
    for(ll i = 0 ; i < v.size() ; i++) cout<<v[i]<<" ";
    cout<<endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n, x, y;
        cin>>n>>x>>y;
        
        string s;
        cin>>s;

        // int steps = abs(x) + abs(y);
        x = abs(x), y = abs(y);

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '4'){
                if(x > y){
                    x--;
                }else{
                    y--;
                }
            }else{
                x--; y--;
                if(x < 0) x = 0;
                if(y < 0) y = 0;
            }
        }

        if(x > 0 || y > 0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }

    return 0;
}