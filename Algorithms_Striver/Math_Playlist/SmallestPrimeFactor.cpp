#include <bits/stdc++.h>
using namespace std;
vector<int> getPrimeFactors(int N)
{
    vector<int> ans;
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            while (N % i == 0)
            {
                N = N / i;
                ans.push_back(i);
            }
        }
    }
    if (N > 1)
    {
        ans.push_back(N);
    }
    return ans;
}
void print(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void SmallestPrimeFactors(vector<int> &arr)
{
    // O(Queries)*O(sqrt(n))
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = getPrimeFactors(arr[i]);
        print(ans);
    }
}
vector<int> SmallPrimeFactor_optimal()
{
    vector<int> spf(100000 + 1);
    for (int i = 1; i <= 100000; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i <= 100000; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= 100000; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}
void anser(vector<int> &arr)
{
    // TC=>O(NloglogN)+O(Queries * log2N)
    //Sc=>O(N)
    vector<int> spf = SmallPrimeFactor_optimal();
    for (int i = 0; i < arr.size(); i++)
    {
        int n = arr[i];

        while (n != 1)
        {
            int an = spf[n];
            cout << an << " ";
            n = n / an;
        }
        cout << endl;
    }
}
int main()
{
    vector<int> ans = {60, 20, 30, 100};
    SmallestPrimeFactors(ans);
    cout << "Optimal" << endl;
    anser(ans);
}