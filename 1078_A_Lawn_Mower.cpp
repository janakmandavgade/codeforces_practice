#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int boards, w;
        cin>>boards>>w;

        int n = boards/w;

        cout << boards - n << endl;
    }

    return 0;
}