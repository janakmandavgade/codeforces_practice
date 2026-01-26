#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v){
    for(int i = 0 ; i < v.size() ; i ++){
            cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> v(n);
        int l = -1, r = -1;
        bool flag = false;
        for(int i = 0 ; i < n ; i ++){
            cin>>v[i];
            if(n - i != v[i] && flag == false) {l = i;flag = true;}
        }

        while(l != -1 && r < n && v[r] != n - l){
            r++;
        }

        // cout<< "L&R are: " <<l <<" " << r << endl;
        if(l == -1){
            printVec(v);
            continue;
        }

        reverse(v.begin()+l, v.begin()+r+1);
        printVec(v);
    }
}