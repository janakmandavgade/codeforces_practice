#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int> v(n);
        map<int,int> mpp;
        for(int i = 0; i < n ; i++){
            cin>>v[i];
            mpp[v[i]]++;
        }
        
        vector<int> rem(k, 0);
        int mex = 0;

        while(true){
            if(mpp.count(mex)){
                rem[mex%k] += mpp[mex];
            }

            if(rem[mex%k] > 0){
                rem[mex%k]--;
                mex++;
            }else{
                cout<<mex<<endl;
                break;
            }
        }
        
    }
    

    return 0;
}