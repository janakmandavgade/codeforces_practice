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
        int x, y;
        cin>>x>>y;
        // cout<<x<<" " << y << endl;
        if(abs(x) < abs(y)) {
            cout<<"NO"<<endl;
            continue;
        }
        while(x>1){
            // cout<<"Before"<<x<<" "<<y<<endl;
            if(y >= 1 && x >= 2){
                int sub = min (x/2, y/1);
                x -= (sub * 2); y -= (sub * 1);
            }
            // cout<<x<<" "<<y<<endl;
            else if(y <= -1 && x >= 4){
                int sub = min (x/4, abs(y/1));
                x -= (sub * 4); y += (sub * 1);
            }
            // cout<<x<<" "<<y<<endl;
            else if(x >= 3 && y == 0){
                int sub = x/3;
                x -= (sub * 3);
            }else break;

        }

        if(x == 0 && y == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
}