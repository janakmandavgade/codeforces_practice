#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        // int n;
        // cin>>n;
        
        int n, m, l;
        cin>>n>>m>>l;

        vector<int> v(n+1);
        v[0] = 0;
        for(int i = 1 ; i <= n ; i++) cin>>v[i];

        multiset<ll> s;

        for(int i = 0 ; i < min(m, n+1) ; i++) s.insert(0);
        int mx = n+1;
        for(int i = 1 ; i <= n ; i++){
            mx--;
            for(int j = v[i-1] ; j < v[i] ; j++){
                s.insert((*s.begin())+1);
                s.erase(s.begin());
            }
            s.erase(--s.end());
            if(s.size() < min(mx, m)) s.insert(0);
        }

        int ans = *(--s.end()) + l - v[n];
        cout<<ans<<endl;
    }

    return 0;
}