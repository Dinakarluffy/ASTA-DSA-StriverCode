#include <bits/stdc++.h>
using namespace std;
// Monotonic Stack means=stored stack value follow specific order
// In the NSE problem you check nearest smallest element present left neighbours only(means left direction only)
vector<int> findNSE(vector<int> &arr)
{
    vector<int> mge(arr.size());
    stack<int> st; // This stack store decreasing order values in given list

    // TC=>O(2n)
    // SC=>O(N)+O(N)
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && st.top() >= arr[i])
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
    vector<int> arr = {1,2,3,4,5,3};
    vector<int> ans = findNSE(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}