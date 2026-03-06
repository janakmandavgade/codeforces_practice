#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int cnt_zeros = 0;
        int cnt_ones = 0;
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++){
            cin>>v[i];

            if(v[i] == -1){
                cnt_ones++;
            }

            if(v[i] == 0){
                cnt_zeros++;
            }
        }

        cout<< cnt_zeros + (cnt_ones%2 == 0 ? 0 : 2) <<endl;
    }
}