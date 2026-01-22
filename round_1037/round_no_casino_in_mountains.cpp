#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n >> k;
        vector<int> v(n);

        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
        }

        int count = 0;
        for(int i = 0 ; i < n ; i++){
            // cout<<"Iteration "<<i;
            if(v[i] == 0){
                // cout<<" element of vector: "<<v[i]<< " " << endl;
                bool if_one = false;
                int ele_traversed = 0;
                for(int j = i ; j < i + k && i + k - 1 < n ; j++){
                    // cout<<"j with ele " << j << ":" << v[j] <<endl;
                    ele_traversed +=1;
                    if(v[j] == 1){
                        if_one = true;
                        break;
                    }
                }
                if(if_one == false && ele_traversed == k){
                    count+=1;
                    i+=k;
                }
                
                // else{}
            }
            
            // cout<<"Count:" << count;
            cout<< endl;
        }
        // cout<<"Final:"<< " ";
        cout<<count<<endl;
    }
}