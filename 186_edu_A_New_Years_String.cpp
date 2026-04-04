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

        if(n < 4){
            cout<<0<<endl;
            continue;
        }

        string s1 = "2026";
        string s2 = "2025";

        bool is_2026_present = false, is_2025_present = false;

        for(int i = 0 ; i < n ; i++){
            bool is_present = true;
            for(int j = 0 ; j < s1.size() ; j++){
                if(s[i + j] != s1[j]){
                    is_present = false;
                    break;
                }
            }
            if(is_present){
                is_2026_present = true;
                break;
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            bool is_present = true;
            for(int j = 0 ; j < s2.size() ; j++){
                if(s[i + j] != s2[j]){
                    is_present = false;
                    break;
                }
            }
            if(is_present){
                is_2025_present = true;
                break;
            }
        }
        
        if(is_2025_present && !is_2026_present){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
        
    }

    return 0;
}