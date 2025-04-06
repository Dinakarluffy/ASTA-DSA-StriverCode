#include <bits/stdc++.h>
using namespace std;
// Problem Statement: Maximum consecutive days for which the stack price was less than an equal to current day
class StockSpannerBruteForce
{

public:
    // For Brute Force :
    // TC=>O(Number of days)
    // SC=>O(total number of next calls)
    vector<int> arr;

    void stackSpanner()
    {
        arr.clear();
    }
    int next(int val)
    {
        int cnt = 1;
        arr.push_back(val);
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            if (arr[i] <= val)
                cnt++;
            else
            {
                break;
            }
        }
        return cnt;
    }
};
class StockSpannerOptimal
{
    //TC=>O(2N)
    //SC=>O(n)
public:
    stack<pair<int, int>> st;
    int ind = -1;
    void stockSpanner()
    {
        ind = -1;
        // st.clear();
    }
    int next(int val)
    {
        ind = ind + 1;
        while (!st.empty() && (st.top().first <= val))
        {
            st.pop();
        }
        int ans = ind + (st.empty() ? -1 : st.top().second);
        st.push({val, ind});
        return ans;
    }
};
int main()
{
}