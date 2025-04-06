#include <bits/stdc++.h>
using namespace std;
void array1d(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {

        cout << a[i];
    }
}
// pass by value in function
void dosomething(int num)
{
    cout << num << endl;
    num += 5;
    cout << num << endl;
}

// Pass by reference in function

void dosome(int &num)
{ // The & symbol take the original value
    cout << num << endl;
    num += 5;
    cout << num << endl;
}

// Function to pass 2D array by reference
void print2DArray(int arr[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to pass 2D array using pointer (Alternative method)
void print2DArrayPointer(int *arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << *(arr + i * cols + j) << " ";
        }
        cout << endl;
    }
}

int main()
{

    int num = 10;
    dosomething(num); // Here num is pass only the copy of it's original num,so original num value that's not change
    cout << num << endl;
    cout << "Pass by value" << endl;

    int num2 = 12;
    dosome(num2);
    cout << num2 << endl;
    cout << "Pass by reference" << endl;

    // Pass array in functions

    // @Arrays always pass by reference

    int n = 5;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        ar[i] = i;
    }

    array1d(ar, n);

    // Handling 2d arrays in function
    int rows = 3, cols = 3;
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // Passing by reference
    cout << "Using pass-by-reference:" << endl;
    print2DArray(arr, rows, cols);

    // Passing by pointer
    cout << "\nUsing pass-by-pointer:" << endl;
    print2DArrayPointer(&arr[0][0], rows, cols);
}