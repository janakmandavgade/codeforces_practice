#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    while(n--){
        int t;
        cin>>t;
        if(t%4 == 0){
            cout << "Bob" <<endl;
        }
        else{
            cout<<"Alice"<<endl;
        }
    }
    return 0;
}