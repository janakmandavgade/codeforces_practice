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
        ll n, k;
        cin>>n>>k;

        int mn = 1, mx = n;

        string s;
        cin>>s;

        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0'){
                cnt = 0;
            }
            else if(s[i] == '1')
                cnt++;
            if(cnt >= k){
                break;
            }
        }
        // cout<<cnt<<endl;
        if(cnt >= k){
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0'){
                ans[i] = mx--;
            }else{
                ans[i] = mn++;
            }
        }

        printVec(ans);
    }

    return 0;
}