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

        vector<int> v(n);
        unordered_map<int,int> mpp;
        int mx_freq = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            cin>>v[i];
            mpp[v[i]]++;
            mx_freq = max(mpp[v[i]], mx_freq);
        }
        
        if(mx_freq >= (n+1)/2){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        
    }

    return 0;
}