#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        int i = 0, j = n-1;
        bool isPal = true;
        while(i < j){
            if(s[i] != s[j]){
                isPal = false;
                break;
            }
            i++;
            j--;
        }

        if(isPal){
            cout<<0<<endl;
            cout<<endl;
        }else{
            // cout<<n<<endl;
            //cnt 1s 
            int cnt = 0;
            for(int i = 0 ; i < n ; i++){
                if(s[i] == '1') cnt++;
            }
            cout<<cnt<<endl;
            for(int i = 0 ; i < n ; i++){
                if(s[i] == '1') cout<<i+1<<" "; 
            }cout<<endl;
        }
    }
}