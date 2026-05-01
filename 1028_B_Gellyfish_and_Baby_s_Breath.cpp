#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
#define MOD 998244353

// Precompute powers to avoid pow() precision issues
const int MAXN = 100005;
ll p2[MAXN];

void precompute()
{
    p2[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        p2[i] = (p2[i - 1] * 2) % MOD;
    }
}

template <typename t, typename size_t>
void inputVec(vector<t> &v, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}

void printVec(vector<ll> &v)
{
    for (ll i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n), b(n), ans;
        inputVec(a, n);
        inputVec(b, n);

        ll i_mx = 0, j_mx = 0;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] > a[i_mx])
                i_mx = i;
            if (b[i] > b[j_mx])
                j_mx = i;

            // Define the exponents of the two candidates
            ll a1 = a[i_mx], b1 = b[i - i_mx]; // Candidate 1 (uses max a)
            ll a2 = a[i - j_mx], b2 = b[j_mx]; // Candidate 2 (uses max b)

            // To compare 2^a1 + 2^b1 vs 2^a2 + 2^b2 accurately:
            // We compare their exponents as pairs {max, min}
            pair<ll, ll> cand1 = {max(a1, b1), min(a1, b1)};
            pair<ll, ll> cand2 = {max(a2, b2), min(a2, b2)};

            if (cand1 > cand2)
            {
                ans.push_back((p2[a1] + p2[b1]) % MOD);
            }
            else
            {
                ans.push_back((p2[a2] + p2[b2]) % MOD);
            }
        }
        printVec(ans);
    }
    return 0;
}