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
        int n;
        
        
        string s;
        cin>>s;

        n = s.size();

        bool is_Start_reached = false, is_End_reached = false;

        int len = INT_MIN;

        int i = 0;
        while(i < n){
            if(i + 1 < n && s[i] == '*' && s[i+1] == '*'){
                break;
            }else if(s[i] == '<' || s[i] == '*'){
                i++;
            }else if(s[i] == '>'){
                break;
            }
        }
        len = max(i+1, len);
        cout<<"Len is: " << len <<endl;
        i = n-1;
        while (i >= 0){
            if(i - 1 >= 0 && s[i] == '*' && s[i-1] == '*'){
                break;
            }else if(s[i] == '>' || s[i] == '*'){
                i--;
            }else if(s[i] == '<'){
                break;
            }
        }
        len = max(len, n - i);

    }

    return 0;
}