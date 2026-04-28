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
        ll n, s;
        cin>>n>>s;

        vector<int> v(n);
        inputVec(v, n);

        int sum = 0, c0 = 0, c1 = 0, c2 = 0;
        for(int i = 0 ; i < n ; i++){
            sum += v[i];
            if(v[i] == 0) c0++;
            if(v[i] == 1) c1++;
            if(v[i] == 2) c2++;
        }

        // three cases 
        if(s < sum){
            printVec(v);
            continue;
        }else if(s == sum){
            cout<<-1<<endl;
            continue;
        }else{
            int d = s - sum;
            if(d != 1){
                cout<<-1<<endl;
                continue;
            }else{
                vector<int> ans;
                for(int i = 0 ; i < c1 ; i++){
                    ans.push_back(1);
                }
                for(int i = 0 ; i < c2 ; i++){
                    ans.push_back(2);
                }
                for(int i = 0 ; i < c0 ; i++){
                    ans.push_back(0);
                }
                printVec(ans);
            }
        }
    }

    return 0;
}