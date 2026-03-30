#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        // int n;
        // cin>>n;
        
        int n, m , l;
        cin>>n>>m>>l;

        vector<int> v(n);
        for(int i = 0 ; i < n ; i++) cin>>v[i];

        int total = l;
        for(int i = 0 ; i < n ; i++){
            int danger_decreased = v[i] / m;
            total -= danger_decreased;
            if(total < 0 ){
                total = 0;
                break;
            }
        }

        int after_no_flashed = (l - v[n-1]) >= 0 ? l - v[n-1] : 0;
        total = total + after_no_flashed;

        cout<<total<<endl;
        
    }

    return 0;
}