#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long int ll;


bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;

    return false;
}

int main(){
    // int t;
    // cin>>t;
    // while(t--){
        // int n;
        // cin>>n;

        vector<string> v(3);
        getline(cin, v[0]);
        getline(cin, v[1]);
        getline(cin, v[2]);

        // for(int i = 0 ; i < 3 ; i++){
        //     cin>>v[i];
        // }

        for(int i = 0 ; i < 3 ; i++){
            vector<int> mpp(26, 0);
            // cout<<v[i]<<endl;
            for(int j = 0 ; j < v[i].size() ; j++){

                if(isVowel(v[i][j])){
                    mpp[v[i][j] - 'a']++;
                }
            }
            int syllables = mpp[0] + mpp[4] + mpp[8] + mpp[14] + mpp[20];
            // cout<<syllables<<endl;
            if(syllables != 5 && (i == 0 || i == 2)){
                cout<<"NO"<<endl;
                return 0;
            }else if(syllables != 7 && (i == 1)){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
        return 0;
    // }
}