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
    
    ll n, k;
    cin>>n>>k;

    vector<ll> v(51);
    v[0] = 1;
    for(ll i = 1; i < 51 ; i++){
        v[i] = v[i - 1] * 2;
    }
    
    bool notFound = true;
    for(ll i = 0 ; i < 50 && notFound ; i++){
        ll a = v[i], d = v[i+1];
        // cout<< i << " " <<  a << " "<<d<<endl;
        // cout<< ((k - a) % d) << endl;
        if((k - a) % d == 0 && (k - a) >= 0){
            cout<<i+1<<endl;
            notFound = false;
        }
    }

    if(notFound){
        cout<<-1<<endl;
    }

    return 0;
}

// every even has one in 0 based indexing:
// every 0, 2, 4, 8, 16, 32 we will get a new value equal to 2's power
// 
//   0. 1. 2. 3. 4. 5. 6. 7. 8. 9. 10 11 12 13 14
//  [1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1].

// 0 2 4 6 8 .... -> 1's -> starts at 1 -> diff 2
// 1 5 9 13 .... -> 2's   -> starts at 2 -> diff 4
// 3, 11, 19 .... -> 3's  -> starts at 4 -> diff 8
// 7, 23 ........ -> 4's  -> starts at 8 -> diff 16



// 2 ^ 50 -> 50 values so 50 iterations ?

// and based upon index we can get values.          (Formula -> x = a + n*d)

// so we have 

// [1, 2, 4, 8, 16, 32, 64 .....]

// i = 0, 
// we have a = 1 and d = v[i]+1;

// 5 ->

// for 0
// a = 1, d = 2

// if(a == n) then a is answer 

// (x-a) % d == 0 then also a is answer

// so 1 !=5
// 5 - 1 / 2 == 0 so yes


// so now for 6

// i = 0;
// a = 1 and d = 2
// 5/2 -> no

// i = 1
// a = 2, d = 4
// 4/4 = 1
// yes
// so v[i] is ans.

// 4 8
