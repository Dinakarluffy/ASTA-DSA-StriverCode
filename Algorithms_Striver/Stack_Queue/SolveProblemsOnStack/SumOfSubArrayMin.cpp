#include <bits/stdc++.h>
using namespace std;

void sumofArrayMin_brute(vector<int> &arr)
{
    int n = arr.size();
    int tot = 0;
    int mod = (int)(1e9 + 7);
    for (int i = 0; i < n; i++)
    {
        int mini = arr[i];
        for (int j = i; j < n; j++)
        {
            mini = min(mini, arr[j]);
            tot = (tot + mini) % mod;
        }
    }
    cout << "The sum of subarray minimum total=> " << tot << endl;
}
vector<int> findNSE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}
vector<int> findPSEE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}
void sumofArrayMin_optimal(vector<int> &arr)
{
    // TC=>O(5N)
    // SC=>O(5N)
    int n = arr.size();
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSEE(arr);
    int tot = 0;
    int mod = (int)(1e9 + 7);
    for (int i = 0; i < n; i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;
        tot = (tot + (right * left * 1LL * arr[i])) % mod;
    }
    cout << tot << endl;
}
int main()
{
    vector<int> arr = {3, 1, 2, 4};
    sumofArrayMin_brute(arr);
    sumofArrayMin_optimal(arr);
}