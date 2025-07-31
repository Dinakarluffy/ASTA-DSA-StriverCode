#include <bits/stdc++.h>
using namespace std;
void printNames(int i, int cnt)
{
    if (i > cnt)
        return;
    cout << "Asta" << " ";

    printNames(i + 1, cnt);
}
void print1ToN(int i, int n)
{
    if (i > n)
        return;
    cout << i << " ";
    print1ToN(i + 1, n);
}
void printNto1(int i, int n)
{
    if (n < i)
        return;
    cout << n << " ";
    printNto1(i, n - 1);
}
void print1ToNbyBacktracking(int i, int n)
{
    if (i < 1)
        return;
    print1ToNbyBacktracking(i - 1, n);
    cout << i << " ";
}
void sumofN2parameters(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    sumofN2parameters(i - 1, sum + i);
}
int sumofN(int n)
{
    if (n == 0)
        return 0;
    return n + sumofN(n - 1);
}
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
int main()
{
    printNames(1, 5);
    cout << endl;
    print1ToN(1, 5);
    cout << endl;
    printNto1(1, 5);
    cout << endl;
    print1ToNbyBacktracking(5, 5);
    cout << endl;
    sumofN2parameters(5, 0);
    cout << endl;
    int ans = factorial(3);
    cout << ans << endl;
}