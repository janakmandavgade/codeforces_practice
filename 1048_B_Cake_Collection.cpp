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
void inputVec(vector<t> &v, size_t n = 0){
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
        ll n, sec;
        cin>>n>>sec;
        
        vector<int> v(n);
        inputVec(v, n);

        sort(v.begin(), v.end(), greater<ll>());

        ll ans = 0;
        for(int i = 0 ; i < n-1 ; i++){
            if(sec > 0){
                ans += sec*v[i];
                sec--; 
            }
        }
        if(sec > 0)
            ans += sec*v[n-1];
        cout<<ans<<endl;
    }

    return 0;
}