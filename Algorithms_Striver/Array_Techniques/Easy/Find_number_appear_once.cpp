#include <bits/stdc++.h>
using namespace std;
void find_number_apearence_once_brute(vector<int> &arr)
{
    // TC=>O(n^2)
    // SC=>O(1)
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
            {
                count++;
            }
        }
        if (count == 1)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}
void find_number_apearence_once_better(vector<int> &arr)
{
    // TC=>O(n)
    // SC=>O(max)
    int n = arr.size();
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int hash[maxi] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}
void find_number_apearence_once_better2(vector<int> &arr)
{
    // SC=>O(n/2+1)

    // TC=>O(nlogM)+O(n/2+1)=>M is n/2+1
    int n = arr.size();
    map<long long, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            cout << it.first << " ";
        }
    }
    cout << endl;
}
void find_number_apearence_once_optimal(vector<int> &arr)
{
    //TC=>O(n)

    //SC=>O(1)
    int n = arr.size();
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1=xor1 ^ arr[i];
    }
    cout<<xor1<<endl;
}
int main()
{
    vector<int> vec = {1, 2, 1, 5, 3, 3, 2};
    // find_number_apearence_once_brute(vec);
    //find_number_apearence_once_better(vec);
    //find_number_apearence_once_better2(vec);
    find_number_apearence_once_optimal(vec);
}