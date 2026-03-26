#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        int cnt_0 = 0, cnt_1 = 0; 
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0') cnt_0++;
            else if(s[i] == '1') cnt_1++;
        }

        if(cnt_0 == n){
            cout<<0<<endl;
        }else if(cnt_0 == 0 || cnt_1 < cnt_0){
            cout<<-1<<endl;
        }else{
            bool isEven = (n%2 == 0);
            
            if(isEven) cout<<cnt_1<<endl;
            else cout<<cnt_0<<endl;

            for(int i = 0 ; i < n ; i++){
                if(isEven && s[i] == '1') cout<<i+1<<" ";
                else if(!isEven && s[i] == '0') cout<<i+1<<" "; 
            }
            cout<<endl;
        }
    }

    return 0;
}