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

void pLine(ll line){
    cout<<"Reached at Line: " << line<<endl;
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
        ll n, m , a, b;
        cin>>n>>m>>a>>b;
        
        vector<pair<ll,ll>> v = {
            {n, b}, {a, m}, {n - a + 1, m}, {n, m - b + 1}
        };

        ll ans = n + m;

        for(auto &[n1, m1] : v){
            ll res = 0;
            
            while(n1 > 1){
                n1 = (n1 + 1)/2;
                res++;
            }

            while(m1 > 1){
                m1 = (m1 + 1)/2;
                res++;
            }

            ans = min(ans, res);
        }

        cout<<ans+1<<endl;
    }

    return 0;
}