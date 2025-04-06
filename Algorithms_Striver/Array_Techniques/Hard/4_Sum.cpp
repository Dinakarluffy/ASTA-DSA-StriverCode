// 4 sum rule arr[i]+arr[j]+arr[k]+arr[l]=0 with unique value;
#include <bits/stdc++.h>
using namespace std;
void four_sum_brute(vector<int> &arr)
{
    // TC=>O(N^4)
    // SC=>2*O(number of quads)
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if (sum == 0)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
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
        cout << endl;
    }
    cout << endl;
}
void four_sum_better(vector<int> &arr)
{
    // TC=>O(N^3) * log(M=vary size)
    // SC=>O(N)+O(number of unique quads )*2
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)

    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                long long sum = (arr[i] + arr[j]);
                sum += arr[k];
                long long fourth = 0 - sum;
                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> ve = {arr[i], arr[j], arr[k], (int)fourth};
                    sort(ve.begin(), ve.end());
                    st.insert(ve);
                }
                hashset.insert(arr[k]);
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
        cout << endl;
    }
    cout << endl;
}
void four_sum_optimal(vector<int> &arr)
{
    // TC=>O(n^2 *n)+ O(n*n)
    // SC=>O(number of the triplets)
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && arr[j] == arr[j - 1])
            {
                continue;
            }
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                sum += arr[l];
                if (sum < 0)
                {
                    k++;
                }
                else if (sum > 0)
                {
                    l--;
                }
                else
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (k < l && arr[k] == arr[j - 1])
                    {
                        k++;
                    }
                    while (k < l && arr[l] == arr[l + 1])
                    {
                        l--;
                    }
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
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<int> v = {1, 0, -1, 0, -2, 2};
    four_sum_brute(v);
    cout << "Better solution" << endl;
    four_sum_better(v);
    cout << "Optimal solution" << endl;
    four_sum_optimal(v);
}