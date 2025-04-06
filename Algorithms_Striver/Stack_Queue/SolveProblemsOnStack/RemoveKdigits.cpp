#include <bits/stdc++.h>
using namespace std;
// Problem Statemeent:remove k digits in string(numbers present):give smallest possible number after removing k digits
// Intuition:Keep smaller digits at first and remove larger numbers
// Edge cases:k<=n,if k==n then return string "0", if return string is "00100" remove the intial zeros(before first 1 appear)
// then return 100
string removekdigits(string &s, int k)
{
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; i++) {
        // Pop from stack if current digit is smaller than the top of stack
        // and we still have digits to remove
        while (!st.empty() && k > 0 && (st.top() - '0') > (s[i] - '0')) {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }

    // If we still have k digits to remove, pop from the stack
    while (k > 0) {
        st.pop();
        k--;
    }

    // If the stack is empty, return "0"
    if (st.empty()) return "0";

    // Build the result string from the stack
    string res = "";
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    // Remove leading zeros
    while (res.size() > 0 && res.back() == '0') {
        res.pop_back();
    }

    // Reverse the result to get the correct order
    reverse(res.begin(), res.end());

    // If the result is empty, return "0"
    if (res.empty()) return "0";
    return res;

}

int main()
{
}