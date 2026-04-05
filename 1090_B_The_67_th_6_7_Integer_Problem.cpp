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
        // int n;
        // cin>>n;

        vector<int> v(7);
        int sum = 0;
        int mx = INT_MIN;
        for(int i = 0 ; i < 7 ; i++) {
            cin>>v[i];
            sum+=v[i];
            mx = max(mx, v[i]);
        }
        // cout<<sum << " " << mx << endl;
        cout<<(-1) * (sum - 2*mx)<<endl;
    }
}