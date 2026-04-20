#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

template<typename t1, typename t2>
ostream& operator<<(ostream &os, pair<t1, t2> p){
    return os << "{" << p.first << ", " << p.second << "}";
}

template <typename t>
void printVec(vector<t> &v){
    for(ll i = 0 ; i < v.size() ; i++) cout<<v[i]<<" ";
    cout<<endl;
    return;
}

template <typename t, typename size_t>
void inputVec(vector<t> &v, size_t n){
    for(size_t i = 0; i < n ; i++){
    cin>>v[i];
    }
}

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
        ll a, b;
        cin>>a>>b;
        if(a == b) {
            cout<<0<<endl;
            // continue;
        }else if(a > b){
            swap(a, b);
            if(b%a == 0) cout<<1<<endl;
            else cout<<2<<endl;
            // continue;
        }else{
            if(b%a == 0) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }

    return 0;
}