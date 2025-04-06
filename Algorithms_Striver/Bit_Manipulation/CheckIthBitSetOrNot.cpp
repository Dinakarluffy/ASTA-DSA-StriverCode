#include <bits/stdc++.h>
using namespace std;

string covert_binary(int n)
{
    string res = "";
    while (n != 0)
    {
        if (n % 2 == 0)
        {
            res += '0';
        }
        else
        {
            res += '1';
        }
        n = n / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}
int countsetbits(int n)
{
    int count = 0;

    while (n > 1)
    {
        if (n % 2 == 1)
            count++;

        n = n / 2;
    }
    if (n == 1)
        count++;
    return count;
}
int countsetbits_opitmal(int n)
{

    // TC=>O(log2 n)
    int count = 0;

    while (n > 1)
    {
        count += n & 1;

        n = n >> 1; // equal to n/2
    }
    if (n == 1)
        count++;
    return count;
}

int countsetbits_opitmal2(int n)
{

    // TC=>O(number fo sets)
    int count = 0;

    while (n != 0)
    {
        n = n & n - 1;
        count++;
    }

    return count;
}
int countsetbits_opitmal3(int n)
{

    // TC=>O(number fo sets)
    int count = 0;

    for (int i = 0; i < 32; i++)
    {
        if (n & (1 << i))
        {
            count++;
        }
    }
    return count;
}
void bitManipulation(int num, int i)
{
    // your code here
    i = i - 1;
    int get_bit = (num & (1 << i)) >> i;
    int set_bit = num | (1 << i);
    int clear_bit = num & (~(1 << i));
    cout << get_bit << " " << set_bit << " " << clear_bit;
}

bool isEven(int n)
{
    // code here
    return !(n & 1);
}

bool isPowerOfTwo(int n)
{
    // Check if n is greater than 0 and if only one bit is set
    return (n > 0) && (n & (n - 1)) == 0;
}
// n: input to count the number of set bits
// Function to return sum of count of set bits in the integers from 1 to n.
int countSetBits(int n)
{
    int count = 0;
    int x = n;
    for (int i = 0; x != 0; i++, x = (x >> 1))
    {
        int pTwo = (1 << i);
        int numberOfGroups = (n + 1) / pTwo;
        count += (numberOfGroups / 2) * pTwo;
        count += ((n >> i) & 1) * ((n + 1) % pTwo);
    }
    return count;
}

int setBit(int n) {
    // Write Your Code here
     return (n | (n + 1));
}
int main()
{
    // Find ith bit is set or not(1 or 0)
    int n = 12;
    int i = 2;
    if (n & (1 << i) != 0) // 0r if (n & (1 >> i) != 0)
    {
        cout << "The given number is set" << endl;
    }
    else
    {
        cout << "The given number is not set" << endl;
    }

    int n1 = 12;
    n1 = n1 | (1 << i); // Set the ith bit

    cout << n1 << endl;

    // Clear the ith bit

    int n2 = 12;

    n2 = n2 & (~(1 << i));

    cout << "clear the ith bit=> " << n2 << endl;

    // Toggle the bit

    int n3 = 13;

    n3 = n3 ^ (1 << i);

    cout << "After toggle the bit =>" << n3 << endl;

    // Remove the last set bit(Right most bit)

    int n4 = 40;

    int res = n4 & (n4 - 1);

    cout << "After remove the last set bit=>" << res << endl;

    string re = covert_binary(res);

    cout << "After remove the last set bit in (binary form)=>" << re << endl;

    // Check if the number is a power of 2

    // In brute force covert the int to binary and check how many 1 present in bianry if 1 means 2 power otherwise not

    int n5 = 8;

    if ((n5 & (n5 - 1)) == 0)
    {
        cout << "The number " << n5 << " is power of 2" << endl;
    }

    else
    {
        cout << "The number " << n5 << " is not power of 2" << endl;
    }
    // Count the number of set bits

    int number = 13;

    int counter = __builtin_popcount(number); // Build in function for count the number of set bits

    cout << "The number of set bits in " << number << " is(built in funciton) =>" << counter << endl;

    int n6 = 30;

    // int count=countsetbits(n6);
    int count = countsetbits_opitmal(n6);

    cout << "The number of set bits in " << n6 << " is(optimal function)  =>" << count << endl;

    int count1 = countsetbits_opitmal2(n6);

    cout << "The number of set bits in " << n6 << " is(optimal2 function) =>" << count1 << endl;
    int count2 = countsetbits_opitmal3(n6);

    cout << "The number of set bits in " << n6 << " is(optimal2 function) =>" << count2 << endl;

    return 0;
}