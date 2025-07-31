#include <bits/stdc++.h>
using namespace std;
void pattern1()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
void patternn1Num()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
void pattern2()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
void pattern2Num1()
{
    int num = 1;
    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            cout << num << " ";
        }
        cout << endl;
        num++;
    }
    cout << endl
         << endl;
}
void pattern2Num2()
{
    int num = 1;
    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
void pattern2Num3()
{
    int num = 1;
    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j < i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
void pattern2Num4()
{
    int num = 1;
    for (int i = 1; i <= 5; i++)
    {
        num = i % 2 == 0 ? 0 : 1;
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num = !num;
        }
        cout << endl;
    }
    cout << endl
         << endl;
}

void pattern3()
{
    for (int i = 5; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
void pattern3Num1()
{
    int n = 5;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5 - (i - 1); j++)
        {
            cout << n << " ";
        }
        n--;
        cout << endl;
    }
    cout << endl
         << endl;
}
void pattern3Num2()
{
    int n = 1;
    for (int i = 1; i <= 5; i++)
    {
        n = 1;
        for (int j = 1; j <= 5 - (i - 1); j++)
        {
            cout << n << " ";
            n++;
        }

        cout << endl;
    }
    cout << endl
         << endl;
}
void pattern4()
{
    int n = 5;
    for (int i = 0; i <= (n * 2) - 1; i++)
    {
        int rowChange = i > n ? (n * 2 - i) : i;
        for (int j = 1; j <= rowChange; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
void pattern5()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= n - i)
                cout << " " << " ";
            else
            {
                cout << "*" << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
void pattern6()
{
    int n = 5;
    for (int i = 5; i > 0; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= n - i)
                cout << " " << " ";
            else
            {
                cout << "*" << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
void pattern7()
{
    int n = 5;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= (i * 2) - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
void pattern5_6()
{
    int n = 5;
    for (int i = 1; i <= (n * 2); i++)
    {
        int row = i > n ? ((n * 2) - i) : i;
        for (int j = 1; j <= (n - row); j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= row; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern8()
{
    int n = 5;
    for (int i = n; i >= 0; i--)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= (i * 2) - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}
void pattern7_8()
{
    int n = 5;
    for (int i = 1; i <= (n * 2); i++)
    {
        int row = i > n ? (n * 2) - i : i;
        for (int j = 1; j <= n - row; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= (row * 2) - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}
void pattern9()
{
    int n = 5;
    for (int i = 1; i <= n * 2; i++)
    {
        int row = i > n ? (n * 2) - i : i;
        for (int j = 1; j <= row; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= n - row + 1; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void pattern10()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        for (int star = 1; star <= (i * 2)-1; star++)
        {
            if (i==n || star == (i * 2)-1 || star == 1)
            {
                cout <<"*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    // pattern1();
    // patternn1Num();
    // pattern2();
    // pattern2Num1();
    // pattern2Num2();
    // pattern2Num3();
    // pattern2Num4();
    // pattern3();
    // pattern3Num1();
    // pattern3Num2();
    // pattern4();
    // pattern5();
    // pattern6();
    // pattern5_6();
    // pattern7();
    // pattern8();
    // pattern7_8();
    // pattern9();
    pattern10();
}