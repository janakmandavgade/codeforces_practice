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
        
        // int i = 0;
        int cnt = 0;
        int last = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '1'){
                last = i;
            }

            if((i > last + k && s[i] == '0')){
                cnt++;
            }
        }

        cout<<cnt<<endl;
    }

    return 0;
}