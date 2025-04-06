#include <bits/stdc++.h>
using namespace std;
void two_sum_brute(vector<int> &arr, int s)
{
    // Tc=>O(N^2)
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if ((arr[i] + arr[j]) == s)
            {
                cout << "The indexs or " << i << " " << j << endl;
            }
        }
    }
}
void two_sum_better(vector<int> &arr, int s)
{
    // Tc=>O(N logN)
    // Sc=>O(N)
    int n = arr.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        int more = s - a;
        if (mp.find(more) != mp.end())
        {
            cout << "Yes " << mp[more] << " " << i << endl; // return {mp[more],i}
        }
        mp[a] = i;
    }
}
void two_sum_optimal(vector<int> &arr, int s)
{
    //TC=>O(n)+O(nlogn)
    //SC=>O(1)
    int n = arr.size();
    int start = 0;
    int last = n - 1;
    sort(arr.begin(), arr.end());
    while (start < last)
    {   
        int sum = arr[start] + arr[last];
        if (sum == s)
        {
            cout << "Yes" << endl;
            break;
        }
        else if (sum < s)
        {
            start++;
        }
        else
        {
            last--;
        }
    }
}

int main()
{
    vector<int> v = {1, 2, 2, 2, 3};
    int sum = 4;
    two_sum_brute(v, sum); 
    two_sum_better(v, sum);
    two_sum_optimal(v,sum);
}