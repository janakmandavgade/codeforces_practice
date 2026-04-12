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

        bool isBroken = false;
        int i;
        for(i = 0 ; i < n ; i++){
            // cout<<i<< " " << v[i] << endl;
            if(i != v[i]){
                cout<<i<<endl;
                isBroken = true;
                break;
            }
        }
        // cout<<"After for:" << i << endl; 
        if(!isBroken){
            cout<<i<<endl;
        }
    }

    return 0;
}