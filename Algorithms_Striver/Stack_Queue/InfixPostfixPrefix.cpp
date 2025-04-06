#include <bits/stdc++.h>
using namespace std;
int priority(char &s)
{

    if (s == '+' || s == '-')
        return 1;
    if (s == '*' || s == '/')
        return 2;
    if (s == '^')
        return 3;
    return -1;
}
string infixToPostfix(string &s)
{
    // TC=>O(n)+O(n)
    // SC=>O(n)+O(n)
    string ans = "";
    stack<char> st;
    int i = 0;
    int n = s.size();
    while (i < n)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop(); // for remove '('
        }
        else
        {
            // For operator

            while (!st.empty() && (priority(s[i]) <= priority(st.top())))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}
// Reverses the string and swaps '(' with ')' and vice versa.
string reverseAndSwap(string s) { // pass by value so we work on a copy
    int i = 0;
    int j = s.size() - 1;
    while(i < j) {
        // Swap parentheses at positions i and j
        if(s[i] == '(')
            s[i] = ')';
        else if(s[i] == ')')
            s[i] = '(';
        
        if(s[j] == '(')
            s[j] = ')';
        else if(s[j] == ')')
            s[j] = '(';
        
        swap(s[i], s[j]);
        i++;
        j--;
    }
    // If odd length, fix the middle element if it's a parenthesis.
    if(i == j) {
        if(s[i] == '(')
            s[i] = ')';
        else if(s[i] == ')')
            s[i] = '(';
    }
    return s;
}

// Simple reversal (without swapping) used after generating the postfix.
string reverseSimple(const string &s) {
    string rev = s;
    int i = 0, j = rev.size() - 1;
    while(i < j) {
        swap(rev[i], rev[j]);
        i++;
        j--;
    }
    return rev;
}

// Converts an infix expression to prefix.
string infixToPrefix(string s) {
    // Step 1: Reverse the infix expression and swap '(' with ')'
    s = reverseAndSwap(s);
    
    stack<char> st;
    string ans = "";
    int n = s.size();
    
    // Step 2: Convert the modified infix expression to postfix.
    for (int i = 0; i < n; i++) {
        // If the character is an operand, add it to the answer.
        if ((s[i] >= 'A' && s[i] <= 'Z') || 
            (s[i] >= 'a' && s[i] <= 'z') || 
            (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        }
        // If opening parenthesis, push onto the stack.
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        // If closing parenthesis, pop until an opening parenthesis is found.
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop(); // Remove '(' from stack.
        }
        // If an operator is encountered.
        else {
            // For right-associative operator '^'
            if (s[i] == '^') {
                while (!st.empty() && priority(s[i]) < priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            // For left-associative operators
            else {
                while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            // Push the current operator onto the stack.
            st.push(s[i]);
        }
    }
    
    // Pop any remaining operators from the stack.
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    
    // Step 3: Reverse the postfix expression to get the prefix expression.
    ans = reverseSimple(ans);
    return ans;
}

string postfixToInfix(string &s)
{
    // TC=>O(n)+O(n1+n2)=>O(n)+O(n)
    // SC=>O(n)
    int i = 0;
    stack<string> st;
    int n = s.size();
    string ans = "";

    while (i < n)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
            st.push(ans);
            ans = "";
        }

        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string s1 = "(" + t2 + s[i] + t1 + ")";
            st.push(s1);
        }

        i++;
    }
    return st.top(); // top element will not be infix expression if the given postfix wrong one
}

string prefixTOinfix(string &s)
{
    // TC=>O(n)+O(n1+n2)=>O(n)+O(n)
    // SC=>O(n)
    int i = s.size() - 1; // we need to access elements from reverse manner
    stack<string> st;
    int n = s.size();
    string ans = "";
    while (i >= 0)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
            st.push(ans);
            ans = "";
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string s1 = "(" + t1 + s[i] + t2 + ")";
            st.push(s1);
        }
        i--;
    }
    return st.top();
}

string postfixToprefix(string &s)
{
    // TC=>O(n)+O(n1+n2)=>O(n)+O(n)
    // SC=>O(n)
    int i = 0; // we need to access elements from reverse manner
    stack<string> st;
    int n = s.size();
    string ans = "";
    while (i < n)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
            st.push(ans);
            ans = "";
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string s1 = s[i] + t2 + t1;
            st.push(s1);
        }
        i++;
    }
    return st.top();
}
string prefixToPostfix(string &s) {
    stack<string> st;
    int n = s.size();

    // Traverse the prefix expression from right to left
    for (int i = n - 1; i >= 0; i--) {
        // If the character is an operand (alphanumeric), push it onto the stack
        if (isalnum(s[i])) {
            st.push(string(1, s[i]));
        } else {
            // When an operator is encountered:
            // Pop two operands from the stack
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            // Concatenate in the order: op1 + op2 + operator
            string expr = op1 + op2 + s[i];
            st.push(expr);
        }
    }

    // The final expression in the stack is the postfix expression
    return st.top();
}

int main()
{
    string s = "a+b*(c^d-e)";
    cout << "Infix To Postfix Answer" << endl;
    string ans = infixToPostfix(s);
    for (auto it : ans)
    {
        cout << it;
    }
    cout << endl;
    cout << "Infix to prefix Answer" << endl;
    string s1 ="(a-b/c)*(a/k-l)";

    string ans1 = infixToPrefix(s1);

    for (auto it : ans1)
    {
        cout << it;
    }
    cout << endl;
    cout << "Postfix to Infix answer" << endl;
    string s2 = "ab-de+f*/";
    string ans2 = postfixToInfix(s2);
    for (auto it : ans2)
    {
        cout << it;
    }
    cout << endl;

    cout << "Prefix to infix answer" << endl;
    string s3 = "*+pq-mn";

    string ans3 = prefixTOinfix(s3);
    for (auto it : ans3)
    {
        cout << it;
    }
    cout << endl;

    cout << "Postfix to Prefix answer" << endl;
    string s4 = "ab-de+f*/";

    // Changed function call below from postfixToInfix to postfixToprefix
    string ans4 = postfixToprefix(s4);

    for (auto it : ans4)
    {
        cout << it;
    }
    cout << endl;

    cout << "Prefix to Postfix answer" << endl;
    string st = "*-A/BC-/AKL"; // Input: Prefix expression

    string answer = prefixToPostfix(st);

    // Output the final postfix expression
    cout << answer << endl;
}
