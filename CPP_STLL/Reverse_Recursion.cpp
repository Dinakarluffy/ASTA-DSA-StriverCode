#include <bits/stdc++.h>
using namespace std;
void reverse(int i, int a[], int n)
{
    if (i >= n / 2)
    {
        return;
    }
    swap(a[i], a[n - i - 1]);
    reverse(i + 1, a, n);
}
bool reverseString(string s, int i, int n)
{
    if (i >= n / 2)
    {
        return true;
    }
    if(s[i]!=s[n-i-1]){
        return false;
    }
    return reverseString(s,i+1,n);
}
int main()
{
    int n = 5;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    cout << "Reverse array using recursion" << endl;

    reverse(0, a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    bool b=reverseString("madam",0,n);
    cout<<"Recusrion using palindrome or not in string"<<endl;
    cout<<b<<endl;
}