#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;

        vector<int> v(n);
        map<int,int> mpp;
        int cnt_np = 0, cnt_equal = 0;
        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
            mpp[v[i]]++;
        }

        for(int i = 0 ; i < k ; i++){
            // cout<<v[i] << ":kkk:" << k << endl;
            
            if(mpp.count(i) == 0) cnt_np++;
            // else if(v[i] < k) cnt_small++;
        }
        cnt_equal = mpp[k];
        cout<<max(cnt_np, cnt_equal)<<endl;
    }
}