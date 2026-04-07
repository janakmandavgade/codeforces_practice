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
        cin>>n;
        unordered_map<char,int> mpp;

        string s;
        cin>>s;

        int mx = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            mpp[s[i]]++;
            mx = max(mx,mpp[s[i]]);
        }

        cout<<n - mpp[s[n-1]]<<endl;
    }

    return 0;
}