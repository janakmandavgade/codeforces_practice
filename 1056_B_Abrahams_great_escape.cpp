#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

// void printVec(vector<ll> &v)
// {
//     for (ll i = 0; i < v.size(); i++)
//         cout << v[i] << " ";
//     cout << endl;
//     return;
// }

// Overload 1: Any single generic type T
template <typename T>
void print(T data)
{
    std::cout << "Single value: " << data << "\n";
}

// Overload 2: Generic 1D Vector
template <typename T>
void print(const std::vector<T> &v)
{
    std::cout << "1D Vector: ";
    for (const auto &i : v)
        std::cout << i << " ";
    std::cout << "\n";
}

// Overload 3: Generic 2D Vector
template <typename T>
void print(const std::vector<std::vector<T>> &v2d)
{
    std::cout << "2D Vector:\n";
    for (const auto &row : v2d)
    {
        for (const auto &val : row)
        {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        if (k == n * n - 1)
        {
            cout << "NO" << endl;
            continue;
        }

        // vector<vector<char>> v(n, vector<char>(n, 'Z'));
        int cnt = 0;
        cout<<"YES"<<endl;
        for (int i = 0; i < n; i++)
        {
            string s = "";

            for (int j = 0; j < n; j++)
            {
                if (k > 0)
                {
                    s += 'U';
                    k--;
                }
                else if (i == n - 1 && j == n - 1)
                {
                    s += 'L';
                }
                else if (i == n - 1)
                {
                    s += 'R';
                }
                else
                {
                    s += 'D';
                }
            }
            cout << s << endl;
        }
        // print(v);
    }

    return 0;
}