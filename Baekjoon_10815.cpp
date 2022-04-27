#include <iostream>
#include <algorithm>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int binarysearch(int* arr, int size, int n){
    int left, right, mid;
    left = 0;
    right = size -1;
    while(left<=right){
        mid = (left + right) / 2;
        if(arr[mid] == n)
            return 1;
        else if(arr[mid]>n)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}

int main()
{
    fastio;
    int n,m;
    cin >> n;
    int* arr;
    arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    cin >> m;
    while(m--){
        int tmp;
        cin >> tmp; 
        cout << binarysearch(arr, n, tmp) << " ";
    }
    return 0;
}