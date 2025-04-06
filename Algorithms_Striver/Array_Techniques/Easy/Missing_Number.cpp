#include <bits/stdc++.h>
using namespace std;
void missing_number_brute(vector<int> &arr)
{
    int n = arr.size();
    // TC=>O(n^2)
    // SC=>O(1)
    // int n1=arr[n-1];
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
void missing_number_better(vector<int> &arr)
{
    // TC=>O(n)+O(n)
    // SC=>O(n)
    int n = arr.size();
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
void missing_number_optimal1(vector<int> &arr)
{
    int n = arr.size();
    // Summation of natural number formula=>(n*(n+1))/2
    // TC=>O(n)
    // SC=>O(1)
    int sum = (n * (n + 2)) / 2;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
    }
    cout << sum - s << endl;
}
void missing_number_optimal2(vector<int> &arr)
{
    int n = arr.size();
    int xor1 = 0;
    int xor2 = 0;
    for(int i=0;i<n;i++){
        xor2=xor2 ^ arr[i];
        xor1=xor1 ^ (i+1);
    }
    xor1=xor1^n;
    cout<<endl<<(xor1^xor2)<<endl;
}
int main()
{
    vector<int> vec = {1, 2, 4, 5};
    missing_number_brute(vec);
    missing_number_better(vec);
    missing_number_optimal1(vec);
    missing_number_optimal2(vec);
}