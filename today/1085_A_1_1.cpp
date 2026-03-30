#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

typedef long long int ll;

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

        for(int i = 1 ; i < n-1 ; i++){
            if(s[i] == '0' && s[i-1] == '1' && s[i+1] == '1'){
                s[i] = '1';
            }
        }

        int mn = 0;
        int mx = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '1'){
                int j = i;
                while(j < n && s[j] == '1') j++;
                // cout<<"i and j: "<<i<<" "<<j<<endl;
                int len = j - i;
                mn += (((len)/2) + 1);
                mx += len;
                // cout<<"Mx and Mn: " << mn << " " << mx << endl;
                i = j - 1;
            }
        }

        cout<<mn<<" "<<mx<<endl;
    }

    return 0;
}