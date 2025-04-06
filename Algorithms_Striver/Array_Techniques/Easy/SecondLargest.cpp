#include <bits/stdc++.h>
using namespace std;
void secondlargest_brute(vector<int> &arr)
{
    /*Normal brute method is sort the array using (merge or quick sort) after that print arr[n-2];
        or largest =arr[n-1];

        //second largest after sorting the array and maxi=arr[n-1] & maxis=0;

        for(int i=n-2;i>=0;i--){
            if(arr[i]!=maxi){
                maxis=arr[i];
                break;
            }
        }


    */

    int n = arr.size();
    int maxi = 0;
    int maxis = 0;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] > arr[maxi])
        {
            maxi = i;
        }
    }
    cout << "The largest element in the array is =>"<<arr[maxi] << endl;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=arr[maxi]){
            maxis=i;
        }
        for(int j=0;j<n;j++){
            if(arr[j]>arr[maxis] && arr[j]!=arr[maxi]){
                maxis=j;
            }
        }
        
    }
    cout <<"The second largest element in the array is=>"<< arr[maxis]<<endl;
}

void secondlargest_better(vector<int>&arr){
    int n=arr.size();
    int large=0;
    int slarge=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[large]){
            large=i;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>slarge && arr[i]!=arr[large]){
            slarge=i;
        }
    }
    cout <<"The largest element in the array is=>"<< arr[large]<<endl;
    cout <<"The second largest element in the array is=>"<< arr[slarge]<<endl;


}
void secondlargest_optimal(vector<int>&arr){
    //TC=>O(N)
    int n=arr.size();
    int large=arr[0];
    int second=-1;//if array contain negative numvers take s=INT_MIN
    for(int i=0;i<n;i++){
        if(arr[i]>large){
            second=large;
            large=arr[i];
        }
        else if(arr[i]<large && arr[i]>second ){
            second=arr[i];
        }
    }
    cout<<"The largest element in the array is=>"<<large<<endl;
    cout <<"The second largest element in the array is=>"<< second;

}

int main()
{
    vector<int> v = {-1,-2,-3};
    secondlargest_brute(v);
    secondlargest_better(v);

}