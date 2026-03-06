#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    bool musicOn = false;
    int vol = 0;
    while(t--){
        int n;
        cin>>n;


        if(n == 1) vol++;
        if(n == 2) {
            if(vol > 0) vol--;
        } 
        if(n  == 3){
            musicOn = !musicOn;
        }

        if(vol >= 3 && musicOn){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

}