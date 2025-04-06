#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 20;
    int temp = n;
    int count = 0;
    while (n > 0)
    {
        int rem = n % 10;
        if (rem > 0)
        {
            if (temp % rem == 0)
            {
                count++;
            }
        }
        n /= 10;
    }
    cout << count;

    int x=20;
    int ans = 0; // Initialize the reversed number to 0
        while (x != 0) {
            int digit = x % 10; // Get the last digit of x
            
            // Check for overflow/underflow before updating ans
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }
            
            ans = ans * 10 + digit; // Append the digit to the reversed number
            x = x / 10; // Remove the last digit from x
        }

        cout<<endl<<ans;
}