#include <bits/stdc++.h>
using namespace std;

int main(){
        int n;
        cin>>n;

        string s;
        cin>>s;


        unordered_map<string,int> mpp;
        for(int i = 0 ; i + 1 < n ; i+=2){
            mpp[s.substr(i, 2)]++;
        }

        string ans = "";
        int mx_freq = -1;

        for(auto [key, val]: mpp){
            if(val > mx_freq){
                mx_freq = val;
                ans = key;
            }
        }
        cout<<ans<<endl;
}