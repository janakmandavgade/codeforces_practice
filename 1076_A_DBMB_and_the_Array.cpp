#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, s, x;
        cin>>n>>s>>x;

        vector<int> v(n);
        int sum = 0;

        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
            sum += v[i];
        }

        // if(sum > s){
        //     cout<<"No"<<endl;
        //     continue;
        // }
        // cout<<"Sum is: " << sum <<" s is:" << s <<endl;
        bool flag = false;
        while(sum <= s){
            if(sum == s){
                cout<<"Yes"<<endl;
                flag = true;
                break;
            }
            sum += x;
            // cout<<sum<<endl;
        }
        if(!flag)
            cout<<"No"<<endl;
    }
}