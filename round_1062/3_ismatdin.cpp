#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt_even = 0, cnt_odd = 0;        
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
            if(v[i] % 2 == 0) cnt_even++;
            else cnt_odd++;
        }
        
        if(cnt_even != 0 && cnt_odd != 0){
            sort(v.begin(), v.end());
        }

        for(int i = 0 ; i < n ; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}