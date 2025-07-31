#include <bits/stdc++.h>
using namespace std;
void squareHollowPattern()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1)
            {
                cout << "*" << " ";
            }
            else if (j == 0 || j == n - 1)
            {
                cout << "*" << " ";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void numberTraingle()
{
    int n = 5;
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void numberIncreasePyramid()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void numberIncreaseReversePyramid()
{
    int n = 5;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void numberChangingPyramid()
{
    int n = 5;
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }

        cout << endl;
    }
}
void zeroChangeTriangle()
{
    int n = 5;
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num = (num == 1) ? 0 : 1;
        }
        cout << endl;
    }
}

int main()
{
    // squareHollowPattern();
    // numberTraingle();
    // numberIncreasePyramid();
    // numberIncreaseReversePyramid();
    // numberChangingPyramid();
    zeroChangeTriangle();
}
