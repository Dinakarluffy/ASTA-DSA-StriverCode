#include <bits/stdc++.h>
using namespace std;
void rearrange_array_elements_sign_brute(vector<int> &arr)
{
    // Positive elements apear in even index,Negative =odd index
    // TC=>O(n)+O(n/2)
    // SC=>O(N/2)+O(N/2)
    int n = arr.size();
    int pos[n / 2] = {0};
    int neg[n / 2] = {0};
    int j = 0;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            neg[k] = arr[i];
            k++;
        }
        if (arr[i] > 0)
        {
            pos[j] = arr[i];
            j++;
        }
    }
    for (int i = 0; i < n / 2; i++)
    {
        arr[2 * i] = pos[i];
        arr[(2 * i) + 1] = neg[i];
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void rearrange_array_elements_sign_optimal(vector<int> &arr)
{
    // TC=>O(n)
    // SC=>O(n)
    int n = arr.size();
    int pos = 0;
    int neg = 1;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            ans[neg] = arr[i];
            neg += 2;
        }
        else
        {
            ans[pos] = arr[i];
            pos += 2;
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
void rearrange_array_elements_sign_better_pos_neg_not_equal_brute(vector<int> &arr)
{
    // In this array positive and negative elements not equal
    //  TC=>O(n)+O(min(pos,neg))+O(leftovers)=>O(2n)
    // SC=>O(n)

    //  SC=>O(N/2)+O(N/2)
    int n = arr.size();
    vector<int> pos, neg;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            neg.push_back(arr[i]);
        }
        else
        {
            pos.push_back(arr[i]);
        }
    }
    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            arr[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> ve = {7, 1, -5, -3, 6, -4};
    rearrange_array_elements_sign_brute(ve);
    rearrange_array_elements_sign_optimal(ve);
    vector<int> v = {7, 1, 2, -3, -4, 3, 4, 5, -2};
    rearrange_array_elements_sign_better_pos_neg_not_equal_brute(v);
}