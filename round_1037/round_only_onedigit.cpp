#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int tmp = n;
        int mn = INT_MAX;
        while(tmp != 0){
            int rem = tmp%10;
            tmp = tmp/10;
            mn = min(mn, rem);
        }
        cout<<mn<<endl;
    }
}