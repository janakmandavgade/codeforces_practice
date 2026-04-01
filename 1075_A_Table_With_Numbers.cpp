#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, h, l;
        cin>>n>>h>>l;

        vector<int> v(n);
        for(int i = 0 ; i < n ; i++) cin>>v[i];

        int cnt_less_than_h = 0;
        int cnt_less_than_l = 0;
        int cnt_useful = 0;
        int ans = 0;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i] <= h) cnt_less_than_h++;
            if(v[i] <= l) cnt_less_than_l++;
            if(v[i] <= h || v[i] <= l) cnt_useful++;
        }

        ans = min({(n/2), cnt_less_than_h, cnt_less_than_l, (cnt_useful/2)});
        cout<<ans<<endl;

    }

    return 0;
}