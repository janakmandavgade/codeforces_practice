#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <unordered_map>
using namespace std;

typedef long long int ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int total_rem = n;
        int ans = 0;
        while(total_rem > 2){
            ans += total_rem/3;
            total_rem = total_rem/3 + total_rem%3; 
        }

        cout<<ans<<endl;
    }
}



// 8
// 8 % 3 = 2 -> Eaten by Hao 8/3 = 2  => 2/2 = 1 * 3 = 3
// 3 % 3 = 0 -> Split equally ? -> hao -> 1 + 2 -> 3  => Carry Forward => 1
// 1 -> Alex


// 9
// 9%3 = 0 -> Eaten by hao ceil(9/3) = 3 Pieces  = > Carry Foward => 3 pieces
// 3%3 = 0 -> eaten by hao ceil(3/3) = 1 piece => carry forward => 1 piece 
// 4 is ans


// 4
// 4 % 3 = 1 -> hao ate -> 1 => ceil(4/3) = 2 => carry forward => 2 pieces 
// 2 pieces -> Alex

// so two cases either total_rem % 3 = 0 || total_rem % 3 != 0 


// 16
// 16 / 3 = 5  -> ceil(16 / 3) = 6
// 5 5 6

// 6
// 6 / 3 = 2
// 2 2 2

// 239
// 79 79 80
// 26 26 27
// 9 9 9
// 3 3 3
// 1 1 1

// 3 -> 1
// 1 1 1

// 4 -> 1
// 1 1 2

// 5 -> 1
// 1 2 2

// 6 -> 2
// 2 2 2

// 7 -> 3
// 2 2 3
// 1 1 1

// 8 -> 3
// 2 3 3
// 1 1 1

// 9 -> 4
// 3 3 3
// 1 1 1

// 10 -> 4
// 3 3 4
// 1 1 2

// 11 -> 4 
// 3 4 4
// 1 1 2

// 12 -> 5 
// 4 4 4
// 1 1 2
