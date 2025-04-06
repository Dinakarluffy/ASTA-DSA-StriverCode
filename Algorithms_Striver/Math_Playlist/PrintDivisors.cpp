#include <bits/stdc++.h>
using namespace std;
vector<int> printDivisors_brute(int N)
{
    // TC=>O(n)
    vector<int> ans;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
vector<int> printDivisors_optimal(int N)
{
    // TC=>O(sqrt(n))
    vector<int> ans;
    for (int i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            ans.push_back(i);
            if (N / i != i)
            {
                ans.push_back(N / i);
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = printDivisors_brute(36);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    vector<int> arr1 = printDivisors_optimal(36);
    for (auto it : arr1)
    {
        cout << it << " ";
    }
}