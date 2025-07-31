#include <bits/stdc++.h>
using namespace std;
void leftRotateNplaces_brute()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 3;
    int n = arr.size();
    int rotate = d % n;
    vector<int> temp;
    for (int i = 0; i < rotate; i++)
    {

        temp.push_back(arr[i]);
    }
    // SHIFTING
    for (int i = rotate; i < n; i++)
    {
        arr[i - rotate] = arr[i];
    }
    // Put it back into array
    int j = 0;
    for (int i = n - rotate; i < n; i++)
    {
        arr[i] = temp[j];
        j++;
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void reverse(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        // int temp = arr[start];
        // arr[start] = arr[end];
        // arr[end] = temp;
        // start+=1;
        // end-=1;
        swap(arr[start++], arr[end--]);
    }
}
void leftRotateNplaces_optimal()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 6;
    int n = arr.size();
    int rotate = d % n;
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
    for (auto it : arr)
    {

        cout << it << " ";
    }
    cout << endl;
}
void moveZerosToEnd_brute()
{
    vector<int> arr = {1, 2, 3, 0, 0, 1, 0, 3};
    int n = arr.size();
    vector<int> temp;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
        else
        {
            count++;
        }
    }
    for (int i = 0; i < count; i++)
    {
        temp.push_back(0);
    }
    for (auto it : temp)
    {
        cout << it << " ";
    }
    cout << endl;
}
void moveZerosToEnd_better()
{
    vector<int> arr = {1, 2, 3, 0, 0, 1, 0, 3};
    int n = arr.size();
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void linearSearch()
{
    vector<int> arr = {1, 2, 3, 4, 5, 4};
    int n = arr.size();
    int count = -1;
    int searchElement = 4;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == searchElement)
        {
            count = i;
            break;
        }
    }
    if (count == -1)
        cout << "Search Element is Not Found" << endl;
    else
    {
        cout << "Serch Element is Found in " << count << " " << "Index in array" << endl;
    }
    cout << endl;
}
void unionOfTwoSortedArrays_brute()
{
    vector<int> arr1 = {1, 1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5};
    int n1 = arr1.size();
    int n2 = arr2.size();
    set<int> st;
    for (int i = 0; i < n1; i++)
    {

        st.insert(arr1[i]);
    }
    for (int i = 0; i < n2; i++)
    {

        st.insert(arr2[i]);
    }
    for (auto it : st)
    {
        cout << it << " ";
    }
    cout << endl;
}
void unionOfTwoSortedArrays_better()
{
    vector<int> arr1 = {1, 1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5};
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> union_array;
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (union_array.size() == 0 || union_array.back() != arr1[i])
            {
                union_array.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (union_array.size() == 0 || union_array.back() != arr2[j])
            {
                union_array.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i < n1)
    {
        if (union_array.size() == 0 || union_array.back() != arr1[i])
        {
            union_array.push_back(arr1[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (union_array.size() == 0 || union_array.back() != arr2[j])
        {
            union_array.push_back(arr2[j]);
        }
        j++;
    }
    for (auto it : union_array)
    {
        cout << it << " ";
    }
    cout << endl;
}
void missingNumber_brute()
{
    vector<int> arr = {1, 2, 4, 3, 6};
    int n = arr.size();
    int start = arr[0];
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << i << endl;
            break;
        }
    }
    cout << endl;
}
void missingNumber_better()
{
    vector<int> arr = {1, 2, 3, 5};
    int n = arr.size();
    vector<int> mp(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == 0)
        {
            cout << i << endl;
            break;
        }
    }
}
void findConsecutiveOnes()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    int n = arr.size();
    int maxi = INT_MIN;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cnt++;
            maxi = max(maxi, cnt);
        }

        else
        {
            cnt = 0;
        }
    }
    cout << maxi << endl;
}
int main()
{
    // leftRotateNplaces_brute();
    // leftRotateNplaces_optimal();
    // moveZerosToEnd_brute();
    // moveZerosToEnd_better();
    // linearSearch();
    // unionOfTwoSortedArrays_brute();
    // unionOfTwoSortedArrays_better();
    // missingNumber_brute();
    // missingNumber_better();
    findConsecutiveOnes();
}