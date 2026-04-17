#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long int ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> v(n);
        for(int i = 0 ; i < n ; i++) cin>>v[i];

        sort(v.begin(), v.end(), greater<int>());

        bool isBlocked = false;
        for(int i = 1 ; i < n ; i++){
            if(v[i-1] == v[i]){
                cout<<-1<<endl;
                isBlocked = true;
                break;
            }
            // sum += v[i];
        }

        if(!isBlocked){
            for(int i = 0 ; i < n ; i++) cout<<v[i]<<" ";
            cout<<endl;
        }
        
    }
}