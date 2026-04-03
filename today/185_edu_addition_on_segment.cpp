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
        int sum = 0;
        int mx = 0;
        for(int i = 0 ; i < n ; i++) {
            cin>>v[i];
            sum += v[i];
            if(v[i] > 0) mx++;
        }

        bool val_found = false;
        for(int i = mx ; i >= 0 ; i--){
            if(sum - i >= n - 1){
                cout<<i<<endl;
                val_found = true;
                break;
            }
        }

        if(!val_found){
            cout<<-1<<endl;
        }
        
    }

    return 0;
}