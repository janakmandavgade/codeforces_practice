#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> v(n);

        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
        }

        sort(v.begin(), v.end());

        int sum = v[0] + v[1], div = 2; 
        for(int i = 2 ; i < n ; i++ ){
            sum += v[i] * div;
            div *= 2;
            // cout<<sum << " " << div << endl;
        }

        cout<<sum/div<<endl;
    }

    return 0;   
}