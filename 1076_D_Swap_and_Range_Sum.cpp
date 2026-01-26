#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin>>n>>q;

    vector<int> v(n), ps(n);

    int s = 0;

    for(int  i= 0 ; i < n ; i++){
        cin>>v[i];
        s+= v[i];
        ps[i] = s;
    }

    while(q--){
        int id;
        cin>>id;

        if(id == 1){
            int pos; cin>>pos;
            pos--;
            int diff = v[pos] - v[pos+1];
            ps[pos] -= diff;
            swap(v[pos], v[pos+1]);

        }else if(id == 2){
            int l, r; cin>>l>>r;
            l--;
            r--;
            if(l == 0) cout<<ps[r]<<endl;
            else{
                cout<<ps[r] - ps[l-1]<<endl;
            }
        }
    }
}