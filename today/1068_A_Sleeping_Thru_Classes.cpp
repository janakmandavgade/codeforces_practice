#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        
        string s;
        cin>>s;
        
        int i = 0;
        int cnt = 0;
        while(i < n){
            if(s[i] == '1'){
                i += (k+1);
                // i = min(i, n);
                if(i >= n) break;
            }else if(i < n && s[i] == '0'){
                cnt++;
                i++;
            }
        }

        cout<<cnt<<endl;
    }

    return 0;
}