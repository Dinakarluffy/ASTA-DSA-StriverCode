#include <bits/stdc++.h>
using namespace std;
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
// BRUTE FORCE
void largeRectangle(vector<int> &arr)
{
    // TC=>O(5N)
    // SC=>O(4N)
    int n = arr.size();
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSEE(arr);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, (arr[i] * (nse[i] - pse[i] - 1)));
    }
    cout << "The largest Rectangle In Histogram is =>" << maxi << endl;
}
void largeRectangle_optimal(vector<int> &arr)
{
    // TC=>O(n)+O(n)
    // SC=>O(n)
    int n = arr.size();
    stack<int> st;
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && (arr[st.top() > arr[i]]))
        {
            int element = st.top();
            st.pop();
            int nse = i;

            int pse = st.empty() ? -1 : st.top();

            int area = (arr[element] * (nse - pse - 1));

            maxArea = max(maxArea, (arr[element] * (nse - pse - 1)));
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int nse = n;
        int element = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top();

        int area = (arr[element] * (nse - pse - 1));

        maxArea = max(maxArea, (arr[element] * (nse - pse - 1)));
    }
    cout << "The largest Rectangle In Histogram(optimal) is =>" << maxArea << endl;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int leftsmall[n], rightsmall[n];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            leftsmall[i] = 0;
        else
            leftsmall[i] = st.top() + 1;
        st.push(i);
    }
    // clear the stack to be re-used
    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        if (st.empty())
            rightsmall[i] = n - 1;
        else
            rightsmall[i] = st.top() - 1;

        st.push(i);
    }
    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    }
    return maxA;
}
int largestRectangleArea(vector<int> &histo)
{
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
        {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}
int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    largeRectangle(arr);
    largeRectangle_optimal(arr);
}