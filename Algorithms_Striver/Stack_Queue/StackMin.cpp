#include <bits/stdc++.h>
using namespace std;
class MinStack
{
    stack<pair<int, int>> st;

public:
    void push(int x)
    {
        int min;
        if (st.empty())
        {
            min = x;
        }
        else
        {
            min = std::min(st.top().second, x);
        }
        st.push({x, min});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};
class MinStackOptimal
{
    std::stack<long long> st; // Stack to store elements
    long long mini;           // Variable to store minimum element

public:
    /** initialize your data structure here. */
    MinStackOptimal()
    {
        while (!st.empty())
            st.pop();     // Clear any previous stack contents (not strictly necessary)
        mini = LLONG_MAX; // Use long long max value instead of INT_MAX
    }

    void push(int value)
    {
        long long val = value;
        if (st.empty())
        {
            mini = val; // Set the minimum to the first element
            st.push(val);
        }
        else
        {
            if (val < mini)
            {
                // If the new value is less than the minimum, we encode it.
                st.push(2 * val - mini); // Encoding logic
                mini = val;              // Update minimum
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        long long el = st.top();
        st.pop();

        if (el < mini)
        {
            // If the element is smaller than the minimum, update the minimum
            mini = 2 * mini - el; // Decode the old minimum from the stack
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        long long el = st.top();
        if (el < mini)
            return mini; // If the top element is encoded, return the current minimum
        return el;
    }

    int getMin()
    {
        return mini; // Return the current minimum element
    }
};
int main()
{
}