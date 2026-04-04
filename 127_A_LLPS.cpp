#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long int ll;

int main(){
    string s;
    cin>>s;

    vector<int> freq(26 , 0);

    for(int i = 0 ; i < s.size() ; i++){
        freq[s[i] - 'a']++;
    }

    string ans;

    for(int i = 25 ; i >= 0 ; i--){
        if(freq[i] != 0) {
            for(int j = 0 ; j < freq[i] ; j++)
                ans.push_back(char(i + 'a'));
            break;
        }
    }

    cout<<ans<<endl;

}

// idea is below

// suppose radar


// r = 2
// d = 1
// a = 2

// raar

// generate all subsequences
// iterate through every one and check if greater than the current and if is palindrome

// 3 Points 
// 1. check for 