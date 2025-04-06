#include <bits/stdc++.h>
using namespace std;
void powerExponentiation_brute(int n, int p)
{
    int ans = n;
    for (int i = 2; i <= p; i++)
    {
        ans *= n;
    }
    cout << ans << endl;
}
void powerExponentiation_optimal(int n, int p)
{
    //TC=>O(log2N)
    int m = p;
    //If power is negative first change to positive
    if (p < 0)
    {
        p = p * p;
    }
    double ans = 1;
    while (p > 0)
    {
        if (p % 2 == 1)
        {
            ans = ans * n;
            p = p - 1;
        }
        else
        {
            p = p / 2;
            n = n * n;
        }
    }
    if (m < 0)
    {
        ans = (1 / ans);
    }
    cout << ans;
}
double myPow(double x, int p) {
    long long m = p;  // Use long long to handle INT_MIN safely

// If power is negative, first change to positive by inverting the base
if (p < 0) {
    x = 1 / x;
    m = -m;  // Make the exponent positive
}

double ans = 1;
while (m > 0) {
    if (m % 2 == 1) {
        ans *= x;  // Multiply by base when exponent is odd
    }
    x *= x;  // Square the base
    m /= 2;  // Halve the exponent
}
return ans;

}
int main()
{
    int n = 2;
    int power = 5;
    powerExponentiation_brute(2, 5);
    powerExponentiation_optimal(2, -1);
}