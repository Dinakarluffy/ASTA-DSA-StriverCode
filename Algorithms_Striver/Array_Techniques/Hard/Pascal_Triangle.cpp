#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
int find_ans_pascal_traingel_NCR(int row, int cln)
{
    // Print the element that place in given row,column for pascal traingle
    // The formula is ncbaser=n!/(r!*(n-r)!)
    // TC=>O(row)
    long long res = 1;
    for (int i = 0; i < cln; i++)
    {
        res = res * (row - i);
        res = res / (i + 1);
    }
    return res;
}
void print_nth_row_pascal_traingle(int n)
{
    // TC=>O(n *column)
    for (int c = 1; c <= n; c++)
    {
        cout << find_ans_pascal_traingel_NCR(n - 1, c - 1) << " ";
    }
    cout << endl;
}
vector<int> print_nth_row_pascal_traingle_optimal(int n)
{
    // TC=>O(n)
    vector<int> ans;
    long long res = 1;
    ans.push_back(1);
    // n=row,i=column
    cout << res << " ";
    for (int i = 1; i < n; i++)
    {
        res = res * (n - i);
        res = res / i;
        cout << res << " ";
        ans.push_back(res);
    }
    cout << endl;
    return ans;
}

vector<vector<int>> print_pascal_to_nth_optimal(int n)
{
    // O(n*n*row)
    vector<vector<int>> ans;
    for (int row = 1; row <= n; row++)
    {

        ans.push_back(print_nth_row_pascal_traingle_optimal(row));
    }

    return ans;
}

int main()
{
    int row = 5, cln = 3;
    int n = find_ans_pascal_traingel_NCR(row - 1, cln - 1);
    cout << n << endl;
    cout<<endl;
    print_nth_row_pascal_traingle(6);
    cout<<endl;
    vector<int>v=print_nth_row_pascal_traingle_optimal(6);
    
    cout<<endl;
    
    
    vector<vector<int>> v1 = print_pascal_to_nth_optimal(6);
    
}