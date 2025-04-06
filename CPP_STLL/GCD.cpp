#include <bits/stdc++.h>
using namespace std;
int main()
{

    // Here we use Euclideon algorithm formaula gcd(a,b)=gcd(a%b,b) where a>b,if between two numbers any one of them is zero other one is gcd

    // TC=>o(logpi(min(a,b)))
    int a = 2, b = 3;
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a == 0)
    {
        cout << b << endl;
    }
    else
    {
        cout << a << endl;
    }
}