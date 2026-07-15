#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int ll;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<vector<int>> v(n - 2);

    // element , frequency
    vector<int> freq(n + 1, 0);

    // element, index of triplet
    unordered_map<int, vector<int>> eleToTriplet;

    for (int i = 0; i < n - 2; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < 3; j++)
        {
            ll value;
            cin >> value;

            freq[value]++;

            eleToTriplet[value].push_back(i);

            tmp.push_back(value);
        }
        v[i] = tmp;
    }

    // Then find first triplet such that freq is 1 of an element

    int eleWithFreqOne = -1;
    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == 1)
        {
            eleWithFreqOne = i;
            break;
        }
    }

    // cout<<117<<endl;

    int idxFirstTriplet = eleToTriplet[eleWithFreqOne][0];

    int eleWithFreqTwo, eleWithFreqThree;

    for (int i = 0; i < 3; i++)
    {
        if (freq[v[idxFirstTriplet][i]] == 2)
        {
            eleWithFreqTwo = v[idxFirstTriplet][i];
        }
        else if (freq[v[idxFirstTriplet][i]] == 3)
        {
            eleWithFreqThree = v[idxFirstTriplet][i];
        }
    }

    vector<int> ans;
    vector<bool> isTripletVisited(n + 1, false);

    ans.push_back(eleWithFreqOne);
    ans.push_back(eleWithFreqTwo);
    ans.push_back(eleWithFreqThree);
    isTripletVisited[idxFirstTriplet] = true;

    for (int i = 1; i + 2 < n; i++)
    {
        // Check in which triplet is ans[2] and ans[3] present in?

        // First check if eleToTriplet Contains equal values for these two elements
        int toFindEle = ans[i];
        int toFindEle2 = ans[i + 1];

        int currTripletIdx = -1;

        for (int tIdx : eleToTriplet[toFindEle])
        {
            bool containsToFindEle2 = false;
            if (isTripletVisited[tIdx])
                continue;

            for (int ele : v[tIdx])
            {
                if (toFindEle2 == ele)
                    containsToFindEle2 = true;
            }

            if (!containsToFindEle2)
                continue;

            isTripletVisited[tIdx] = true;

            for (int ele : v[tIdx])
            {
                if (ele != toFindEle && ele != toFindEle2)
                {
                    ans.push_back(ele);
                    break;
                }
            }
            break;
        }
    }

    printVec(ans);

    return 0;
}