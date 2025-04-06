#include <bits/stdc++.h>
using namespace std;
// Monotonic Stack means=stored stack value follow specific order
//In the NGE problem you check greater element present right neighbours only(means right direction only)
vector<int> findNGE(vector<int> &arr)
{
    vector<int> mge(arr.size());
    stack<int> st; // This stack store decreasing order values in given list

    // TC=>O(2n)
    // SC=>O(N)+O(N)
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            mge[i] = -1;
        }
        else
        {
            mge[i] = st.top();
        }
        st.push(arr[i]);
    }
    return mge; 
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