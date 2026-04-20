#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long int ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> v(n), idx(n+1);
        for(int i = 0 ; i < n ; i++) {
            cin>>v[i];
        } 

        bool flag = true;
        int l = 0, r = n - 1;
        for(int i = 1 ; i <= n ; i++){
            // cout<<v[i] << v[n - i - 1] << endl;
            if(v[l] == i){
                l++;
            }else if(v[r] == i){r--;}
            else{
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
        }

        if(flag){
            cout<<"YES"<<endl;
        }
    }
}


// 2 3 1 6 5 4 

// 1 2 3 4

// 1 2 4 3
// 1 2 3 3
// 1 2 2 2
// 1 1 1 1
// 0 0 0 0 

// 2 1 3 4
// 2 1 3 3
// 2 1 2 2

// Obs: 1 will always protect the ones on left
// Obs 2: 

// 2 1 3 4 5
// 2 1 3 3 4
// 2 1 3 3 3
// 2 1 2 2 2

// 5 2 1 3 4
// 4 2 1 3 4
// 

// so no of a[i] > a[i+1] X
// idts dist if n and n + 1 matters
// Position of smallest matters ig

// pattern 
// either 
// n    n+1 at ends or  n+1 n at ends