#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        int y_cnt = 0;

        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'Y') y_cnt++;
        }

        if(y_cnt >= 1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}