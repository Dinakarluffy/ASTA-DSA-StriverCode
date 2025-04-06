

#include <bits/stdc++.h>
using namespace std;

double median_brute(vector<int> &a, vector<int> &b)
{
    // size of two given arrays:
    int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    // apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            arr3.push_back(a[i++]);
        else
            arr3.push_back(b[j++]);
    }

    // copy the left-out elements:
    while (i < n1)
        arr3.push_back(a[i++]);
    while (j < n2)
        arr3.push_back(b[j++]);

    // Find the median:
    int n = n1 + n2;
    if (n % 2 == 1)
    {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
}
double median_better(vector<int> &a, vector<int> &b)
{
    // size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; // total size
    // required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    // apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if (cnt == ind1)
                ind1el = a[i];
            if (cnt == ind2)
                ind2el = a[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                ind1el = b[j];
            if (cnt == ind2)
                ind2el = b[j];
            cnt++;
            j++;
        }
    }

    // copy the left-out elements:
    while (i < n1)
    {
        if (cnt == ind1)
            ind1el = a[i];
        if (cnt == ind2)
            ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            ind1el = b[j];
        if (cnt == ind2)
            ind2el = b[j];
        cnt++;
        j++;
    }

    // Find the median:
    if (n % 2 == 1)
    {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}
double median_optimal(vector<int> &a, vector<int> &b)
{
    // Binary search do it on length less array because reduce the time complexity,that's all
    int n1 = a.size();
    int n2 = b.size();
    if (n1 > n2)
        return median_optimal(b, a);
    int low = 0;
    int high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;
    while (low <= high)
    {
        int mid1 = (low + high)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        if (mid1 < n1)
        {
            r1 = a[mid1];
        }
        if (mid2 < n2)
        {
            r2 = b[mid2];
        }
        if (mid1 - 1 >= 0)
        {
            l1 = a[mid1 - 1];
        }
        if (mid2 - 1 >= 0)
        {
            l2 = b[mid2 - 1];
        }
        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
            {
                max(l1, l2);
            }
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}
int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median_brute(a, b) << '\n';
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median_better(a, b) << '\n';
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median_optimal(a, b) << '\n';
}
