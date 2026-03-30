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

        int mx = 0, mn = 0, i = 0;
        //find consecutive ones
        while(i < n){
            int j = i;
            while(j < n && s[j] == '1'){
                j++;
            }
            int len = j - i;
            i = j - 1;
            mx += len;
            mn += (len/2) + 1;
            i++;
        }

        cout<<mn<<" "<<mx<<endl;
    }

    return 0;
}