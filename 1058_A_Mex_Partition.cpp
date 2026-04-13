#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++) cin>> v[i];

        sort(v.begin(), v.end());

        bool isBroken = false;
        int i;
        int changes = 0;
        int val = 0;
        for(i = 0 ; i < n ; i++){
            // cout<<i<< " " << v[i] << endl;
            if(v[i] != val) break;
            while(i < n && v[i] == val){
                i++;
            }
            val++;
            i--;
        }
        // cout<<"After for:" << i << endl; 
        // if(!isBroken){
            cout<<val<<endl;
        // }
    }

    return 0;
}