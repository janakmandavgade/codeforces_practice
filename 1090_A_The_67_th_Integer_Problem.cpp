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

        if(n >= 0 && n < 67) cout<<n+1<<endl;
        else cout<<(n)<<endl;
    }
}