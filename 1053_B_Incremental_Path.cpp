#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

typedef long long int ll;

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2> &p){
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

template <typename T>
void printVec(const vector<T> &v){
    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

template <typename T>
void printVec(const vector<vector<T>> &v){
    for(int i = 0 ; i < v.size() ; i++){
        for(int j = 0 ; j < v[i].size() ; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
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
        ll n, m;
        cin>>n>>m;
        
        string s;
        cin>>s;

        vector<int> v(m);
        set<int> st;
        for(int i = 0 ; i < m ; i++){
            cin>>v[i];
            st.insert(v[i]);
        }

        int cur = 1;
        for(int i = 0 ; i < n ; i++){
            cur++;
            // cur++;
            if(s[i] == 'B'){
                while(st.find(cur) != st.end()) cur++;
            }
            st.insert(cur);
            if(s[i] == 'B')
                while(st.find(cur) != st.end()) cur++;
        }

        cout<<st.size()<<endl;
        for(auto &it: st){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}