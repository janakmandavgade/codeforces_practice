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
        //bad implementation
        // if(n%2 == 0){
        //     v[n-1] = n;
        //     v[n-2] = 1;
        // }else{
        //     v[n-1] = 1;
        //     v[n-2] = n;
        // }
        // map<int,int> mpp;
        // mpp[n]++;mpp[1]++; 
        // // mpp[0]++;

        // for(int i = n - 2 ; i > 0 ; i--){
        //     if(mpp.find(v[i] - i) == mpp.end() && v[i] - i > 1){
        //         v[i-1] = v[i] - i;
        //         mpp[v[i] - i]++;
        //     }else if(mpp.find(v[i] + i) == mpp.end() && v[i] + i < n){
        //         v[i-1] = v[i] + i;
        //         mpp[v[i] + i]++;
        //     }
        // }
        int val = (n + 1)/2;
        int cnt = 0;
        for(int i = 0 ; i < n ; i+=2){
            v[i] = val - cnt;
            cnt++;
        }
        cnt = 0;
        val++;
        for(int i = 1 ; i < n ; i+=2){
            v[i] = val + cnt;
            cnt++;
        }
        

        for(auto &it:v) cout<<it<<" "; cout<<endl;

    }
}