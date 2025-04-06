#include <bits/stdc++.h>
using namespace std;
// In the NGE problem you check greater element in whole list(like circular direction = start from right to left)
void nge2(vector<int> &arr)
{
    // TC=>O(N^2)
    // SC=>O(n)
    int n = arr.size();
    vector<int> mge(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j = i + n - 1)
        {
            int index = j % n;
            if (arr[index] > arr[i])
            {
                mge[i] = arr[index];
                break;
            }
        }
    }
}
vector<int> findNGE(vector<int> &arr)
{
    vector<int> nge(arr.size());
    stack<int> st; // This stack store decreasing order values in given list

    // TC=>O(4n)
    // SC=>O(2N)+O(N)
    int n = arr.size();
    for (int i = (2 * n - 1); i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i % n])
        {
            st.pop();
        }
        if (i < n)
        {
            nge[i] = st.empty() ? -1 : st.top();
        }
        
        st.push(arr[i%n]);
    }
    return nge;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 7, 2, 3};
    vector<int> ans = findNGE(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}