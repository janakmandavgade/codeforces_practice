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

        int r, y;
        cin>>y>>r;

        int c_r = 0, c_y = 0;
        while(r > 0){
            r--;
            c_r++;
        }
        while(y > 1){
            y-=2;
            c_y++;
        }

        cout<<min(n, c_r+c_y)<<endl;
    }
}