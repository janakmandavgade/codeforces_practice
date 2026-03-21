#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    return a[a.size() - 1] < b[b.size() - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> v(n);

        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            vector<int> tmp(m);
            for (int j = 0; j < m; j++)
            {
                cin >> tmp[j];
            }
            v[i] = tmp;
        }

        // for(int i = 0 ; i < v[0].size() ; i++){
        //     cout<<v[0][i] << " ";
        // }cout<<endl;

        sort(v.begin(), v.end(), comp);
        
        // for(int i = 0 ; i < v[0].size() ; i++){
        //     cout<<v[0][i] << " ";
        // }cout<<endl;
        
        // for (int i = 0; i < n; i++)
        // {
        //     int m = v[i].size();
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << v[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        map<int,int> mpp;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            int m = v[i].size();
            for(int j = m-1 ; j >= 0 ; j--){
                int ele = v[i][j];
                if(mpp.find(ele) == mpp.end()){
                    ans.push_back(ele);
                    mpp[ele]++;
                }
            }
        }

        for(int i = 0 ; i < ans.size() ; i++){
            cout<<ans[i] << " ";
        }cout<<endl;
    }

    return 0;
}