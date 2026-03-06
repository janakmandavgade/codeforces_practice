#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    // Invalid case
    if (r > n) return 0;  
    // Base cases
    if (r == 0 || n == r) return 1;    

    double res = 0;
    for (int i = 0; i < r; i++) {
        // log(n!) - log(r!) - log((n-r)!)
        res += log(n - i) - log(i + 1);  
    }

    return (int)round(exp(res));
}

long long C3(long long k) {
    if (k < 3) return 0;
    return k * (k - 1) * (k - 2) / 6;
}

int main(){

    int n, m;
    cin>>n>>m;

    if(n < 3){
        // cout<<(0 + " ") * n <<endl;
        for(int i = 0 ; i < n ; i++){
            cout<<0<<" ";
        }
        return 0;
    }

    vector<vector<int>> adj(n);
    
    for(int i = 0 ; i < m ; i++){
        int a,b;
        cin>>a>>b;

        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);

    }

    for(int i = 0 ; i < n ; i++){
        long long sz = adj[i].size();
        long long k = n - sz - 1;
        if(k >= 3)
            // cout<<nCr(n - sz - 1, 3)<<" ";
            cout << C3(k) << " ";
        else{
            cout<<0<<" ";
        }
    }
    // cout<<endl;
}