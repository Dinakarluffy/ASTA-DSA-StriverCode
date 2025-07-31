#include <bits/stdc++.h>
using namespace std;
void print_Odd_Even()
{
    int num = 55;
    if (num % 2 == 0)
    {
        cout << "Even" << endl;
    }
    else
    {
        cout << "Odd" << endl;
    }
}
void checkVowel()
{
    char c = 'b';
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        cout << "Vowel";
    else
    {
        cout << "Consanents" << endl;
    }
}
void findGreatestNumber()
{
    int a = 110;
    int b = 33;
    int c = 12;
    if (a > b && a > c)
        cout << "A is greater" << endl;
    else if (b > c && b > a)
        cout << "B is Greater" << endl;
    else
        cout << "C is greater" << endl;
}
void checkPositive()
{
    int a = -1;
    if (a > 0)
        cout << "Positive" << endl;
    else
        cout << "Negative" << endl;
}
void checkAlphabet()
{
    char c = '2';
    if (c >= 'a' && c <= 'z')
        cout << "Alphabet" << endl;
    else
        cout << "Not Alphabet" << endl;
}
void NumberOfDigit()
{
    int n = 999000;
    int count = 0;
    while (n > 0)
    {
        count++;
        n = n / 10;
    }
    cout << count << endl;
}
void SumofDigit()
{
    int n = 9991;
    int rem = 0;
    int product = 1;
    while (n > 0)
    {
        rem = rem + (n % 10);
        product = product * (n % 10);
        n = n / 10;
    }
    cout << rem << endl;
    cout << "Product of Number =>" << product << endl;
}
void reverseNumber()
{
    int n = 999901;
    int reverse = 0;
    while (n > 0)
    {
        reverse = (reverse * 10) + (n % 10);
        n = n / 10;
    }
    cout << reverse << endl;
}
void sumofNumberRange()
{
    int start = 5;
    int end = 7;
    int sum = 0;
    while (start <= end)
    {
        sum = sum + start;
        start++;
    }
    cout << sum << endl;
}
void checkPrime()
{
    int a = 6;
    int cnt = 0;
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0)
            cnt++;
    }
    if (cnt == 2)
        cout << "Prime" << endl;
    else
        cout << "Not Prime Number" << endl;
}
void powOfNumber()
{
    int a = 2;
    int pow = 3;
    int ans = 1;
    while (pow > 0)
    {
        ans = ans * a;
        pow--;
    }
    cout << ans << endl;
}
void Armstrong()
{
    int a = 1636;
    int cnt = 0;
    int temp = a;
    while (temp > 0)
    {
        cnt++;
        temp /= 10;
    }
    int sum = 0;
    int te = a;
    while (te > 0)
    {
        sum = sum + pow((te % 10), cnt);
        te /= 10;
    }
    if (sum == a)
        cout << "Armstrong" << endl;
    else
        cout << "Not Armstrong" << endl;
}
int fact(int n)
{
    int pro = 1;
    for (int i = 1; i <= n; i++)
    {
        pro = pro * i;
    }
    return pro;
}
void strongNumber()
{
    int a = 145;
    int temp = a;
    int sum = 0;
    while (temp > 0)
    {
        sum = sum + fact(temp % 10);
        temp = temp / 10;
    }
    if (sum == a)
        cout << "Strong Number" << endl;
    else
        cout << "Not strong Number" << endl;
}
void ToggleCharecter()
{
    string name = "Apple";
    int n = name.size();
    for (int i = 0; i < n; i++)
    {
        if (isupper(name[i]))
            name[i] = tolower(name[i]);
        else
            name[i] = toupper(name[i]);
    }
    cout << name << endl;
}
void reverseString()
{
    string name = "Apple";
    int i = 0;
    int j = name.size()-1;
    while (i < j)
    {

        swap(name[i], name[j]);
        i++;
        j--;
    }
    cout << name << endl;
}
int main()
{

    print_Odd_Even();
    checkVowel();
    findGreatestNumber();
    checkPositive();
    checkAlphabet();
    NumberOfDigit();
    SumofDigit();
    reverseNumber();
    sumofNumberRange();
    checkPrime();
    powOfNumber();
    Armstrong();
    strongNumber();
    ToggleCharecter();
    reverseString();
}