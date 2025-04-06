// 3 sum rule arr[i]+arr[j]+arr[k]=0 with unique value;
#include <bits/stdc++.h>
using namespace std;
void three_sum_brute(vector<int> &arr)
{
    // TC=>O(N^3) * log(number of tripletes)
    // SC=>2*O(number of tripletes)
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());

    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
    }
    cout << endl;
}
void three_sum_better(vector<int> &arr)
{
    // TC=>O(N^2) * log(M=vary size)
    // SC=>O(N)+O(number of unique triplets )*2
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)

    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(arr[i] + arr[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> ve = {arr[i], arr[j], third};
                sort(ve.begin(), ve.end());
                st.insert(ve);
            }
            hashset.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
    }
    cout << endl;
}
void three_sum_optimal(vector<int> &arr)
{
    //TC=>O(n logn)+ O(n*n)
    //SC=>O(number of the triplets)
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                {
                    j++;
                }
                while (j < k && arr[k] == arr[k + 1])
                {
                    k--;
                }
            }
        }
    }
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
    }
    cout << endl;
}

int main()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    three_sum_brute(v);
    three_sum_better(v);
    three_sum_optimal(v);
}