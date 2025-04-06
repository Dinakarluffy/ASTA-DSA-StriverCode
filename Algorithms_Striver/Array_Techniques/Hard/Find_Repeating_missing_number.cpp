#include <bits/stdc++.h>
using namespace std;
void find_repeating_missing_number_brute(vector<int> &arr)
{
    // TC=>O(n^2)
    // SC=>O(1)
    int n = arr.size();
    int repeat = -1;
    int missing = -1;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                cnt++;
            }
        }
        if (cnt == 2)
        {
            repeat = i;
        }
        else if (cnt == 0)
        {
            missing = i;
        }
        if (missing != -1 && repeat != -1)
        {
            break;
        }
    }
    cout << "Repeating number=>" << repeat << "\nMissing number=>" << missing << endl;
}
void find_repeating_missing_number_better(vector<int> &arr)
{
    // TC=>O(2n)
    // SC=>O(n)
    int n = arr.size();
    int hash[n + 1] = {0};
    int repeat = -1;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    int missing = -1, repeating = -1;
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
            repeating = i;
        else if (hash[i] == 0)
            missing = i;
        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }
    cout << "Repeating number=>" << repeating << "\nMissing number=>" << missing << endl;
}
void find_repeating_missing_number_optimal1(vector<int> &arr)
{
    // Optimal solution 1 is using Math
    //  TC=>O(n)
    //  SC=>O(1)
    long long n = arr.size();
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (1 + 2 * n)) / 6;
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += (long long)arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }
    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2 / val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    cout << "Repeating number=>" << (int)x << "\nMissing number=>" << (int)y << endl;
}
void find_repeating_missing_number_optimal2(vector<int> &arr)
{
    // Optimal solution 2 is using XOR 
    //  TC=>O(n)
    //  SC=>O(1)
    long long n = arr.size();
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        xr = xr ^ (i + 1);
    }
    int bitNo = 0;//or xr & ~(xr-1);
    while (1)
    {
        if ((xr & (1 << bitNo)) != 0)
        {
            break;
        }
        bitNo++;
    }
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        // part of 1 club
        if ((arr[i] & (1 << bitNo)) != 0)
        {
            one = one ^ arr[i];
        }
        // zero club
        else
        {
            zero = zero ^ arr[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // part of 1 club
        if ((i & (1 << bitNo)) != 0)
        {
            one = one ^ i;
        }
        // zero club
        else
        {
            zero = zero ^ i;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == one)
        {
            cnt++;
        }
    }
    if (cnt == 2)
    {
        cout << "Repeating number=>" << one << "\nMissing number=>" << zero << endl;
    }
    else
    {
        cout << "Repeating number=>" << zero << "\nMissing number=>" << one << endl;
    }
    // return {one,zero}
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    find_repeating_missing_number_brute(a);
    find_repeating_missing_number_better(a);
    find_repeating_missing_number_optimal1(a);
    find_repeating_missing_number_optimal2(a);
}