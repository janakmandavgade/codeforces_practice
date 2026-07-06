#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long int ll;
#define MOD 1000000007

template <typename t1, typename t2>
ostream &operator<<(ostream &os, pair<t1, t2> p)
{
    return os << "{" << p.first << ", " << p.second << "}";
}

template <typename t>
void printVec(vector<t> &v)
{
    for (ll i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return;
}

template <typename t>
void print2dVec(vector<vector<t>> &v)
{
    for (ll i = 0; i < v.size(); i++)
    {
        for (ll j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

template <typename t, typename size_t>
void inputVec(vector<t> &v, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}

template <typename t, typename size_t>
void input2dVec(vector<vector<t>> &v, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            cin >> v[i][j];
    }
}

void pLine(ll line)
{
    cout << "Reached at Line: " << line << endl;
}

void printVec(vector<ll> &v)
{
    for (ll i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return;
}

void find_prime(ll n, unordered_set<ll> &primes)
{
    while (n % 2LL == 0)
    {
        primes.insert(2);
        n = n / 2LL;
    }

    for (ll i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            primes.insert(i);
            n = n / i;
        }
    }

    if (n > 2)
    {
        primes.insert(n);
    }

    // so we now have primes
}

ll binpow(ll a, ll b)
{
    ll result = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            result = ((result * a) % MOD);
        }

        a = ((a * a) % MOD);
        b = b >> 1;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll num, n;
    cin >> num >> n;

    unordered_set<ll> primes;
    find_prime(num, primes);

    // cout << "Printing Primes" << endl;

    // for (auto it = primes.begin(); it != primes.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;

    // printVec(primes);

    ll ans = 1;
    // auto it = primes.begin();
    for (auto it = primes.begin(); it != primes.end(); it++)
    {
        // For every prime calculate if p^k is feasible and divide by ans
        ll power = 0;
        ll num = *it;
        while (num <= n)
        {
            power += ((n / num));

            if (num > n / (*it))
                break;
            num *= (*it);
        }
        // cout << *it << endl;
        // cout << power << " " << num << endl;

        ans = ((ans * (binpow(*it, power) % MOD)) % MOD);
    }

    cout << ans << endl;

    return 0;
}