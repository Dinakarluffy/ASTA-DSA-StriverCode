#include <bits/stdc++.h>
using namespace std;
// Don't use division operator
int printDivideTwoNumber_brute(int divident, int divisor)
{
    // TC=>O(divident)
    bool sign = true;

    if (divident >= 0 && divisor < 0)
        sign = false;
    if (divident < 0 && divisor >= 0)
        sign = false;

    int sum = 0;
    int cnt = 0;
    while (sum + divisor <= divident)
    {
        cnt += 1;
        sum += divisor;
    }
    if (cnt >= pow(2, 31) && sign == true)
    {
        return INT_MAX;
    }
    if (cnt >= pow(2, 31) && sign == false)
    {
        return INT_MIN;
    }

    return sign ? cnt : -cnt;
}
int printDivideTwoNumber_optimal(int divident, int divisor)
{

    // TC=>O()
    if (divident == divisor)
        return 1;
    bool sign = true; //+ve
    if (divident >= 0 && divisor < 0)
        sign = false;
    if (divident < 0 && divisor >= 0)
        sign = false;

    long n = abs(divident);
    long d = abs(divisor);
    long ans = 0;
    while (n >= d)
    {
        int cnt = 0;
        while (n >= (d << (cnt + 1)))
        {
            cnt++;
        }
        ans += (1 << cnt); // 2^cnt
        n = n - (d * (1 << cnt));
    }

    if (ans >= pow(2, 31) && sign == true)
    {
        return INT_MAX;
    }
    if (ans >= pow(2, 31) && sign == false)
    {
        return INT_MIN;
    }
   
    return sign ? ans : (-1 * ans);
}

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    while (dvd >= dvs) {
        long temp = dvs, m = 1;
        while (temp << 1 <= dvd) {
            temp <<= 1;
            m <<= 1;
        }
        dvd -= temp;
        ans += m;
    }
    return sign * ans;
}
int main()
{
    int n1 = printDivideTwoNumber_brute(22, -3);
    cout << n1 << endl;
    int n = printDivideTwoNumber_optimal(22, -3);
    cout << n;
}