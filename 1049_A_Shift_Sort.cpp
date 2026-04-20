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
        ll n;
        cin>>n;
        
        string s;
        cin>>s;

        // cout<<"Health ok: 28" << endl;

        int cnt_0 = 0, cnt_1 = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0') cnt_0++;
            else cnt_1++;
        }

        // cout<<"Health ok: 28" << endl;

        int ans = 0;
        for(int i = n-1 ; i >= n - cnt_1 ; i--){
            if(s[i] == '0') ans++;
        }
        //handle case where every 0
        ans = (ans == cnt_0 && cnt_0 == n) ? 0 : ans;
        cout<<ans<<endl;
    }

    return 0;
}