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
        
        int win = n, lose = 0;
        int matches = 0;
        while(!(win == 1 && lose == 1)){
            int winMatches = win/2;
            int loseMatches = lose/2;

            win -= winMatches;
            lose = lose - loseMatches + winMatches;
            matches += winMatches + loseMatches;
        }
        // cout<<"Win and Loss are:" << win << " " << lose << endl;
        cout<<matches+1<<endl;
    }

    return 0;
}