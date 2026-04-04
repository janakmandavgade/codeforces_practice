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
        
        int mx = INT_MIN;
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = n - 1 ; j >= 0 ; j--){
                int cv = i*n + j + 1;
                // cout<<cv<<" ";

                if(i + 1 < n){
                    int r_plus_1 = (i+1)*n + (j+1);
                    cv += r_plus_1;
                    // cout<<r_plus_1<<" ";
                }
                if(i - 1 >= 0){
                    int r_minus_1 =(i-1)*n + (j+1);
                    cv += r_minus_1;
                    // cout<<r_minus_1<<" ";
                }
                if(j + 1 < n){
                    int c_plus_1 = i*n + j + 2;
                    cv += c_plus_1;
                    // cout<<c_plus_1<<" ";
                }
                if(j - 1 >= 0){
                    int c_minus_1 = i*n + j;
                    cv += c_minus_1;
                    // cout<<c_minus_1<<" ";
                }
                mx = max(cv, mx);
                // break;
            }
            // break;
        }
        cout<<mx<<endl;
        // cout<<"Ende"<<endl;
    }

    return 0;
}