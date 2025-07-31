#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=2,m=3;
    int n1=3,m1=2;
    int arr[n][m];
    int arr1[n1][m1];
    cout << "Enter the elements of first matrix: " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    cout << "Enter the elements of second matrix: " << endl;
    for(int i=0;i<n1;i++){
        for(int j=0;j<m1;j++){
            cin >> arr1[i][j];
        }
    }
    int ans[n][m1];
    cout << "The product of the two matrices is: " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m1;j++){
            int sum=0;
            for(int k=0;k<m;k++){
                sum+=arr[i][k]*arr1[k][j];
            }
            ans[i][j]=sum;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m1;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
}