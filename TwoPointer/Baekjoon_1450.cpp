#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

void makeSums(int start, int end, vector<ll>& arr, vector<ll>& vec, ll sum){
    if(start>end){
        vec.push_back(sum);
    }
    else{
        makeSums(start+1, end, arr, vec, sum);
        makeSums(start+1, end, arr, vec, sum + arr[start]);
    }
}

int main()
{
    int N, C;
    cin >> N >> C;

    vector<ll> arr;
    arr.resize(N,0);
    for(int i=0; i<N; i++)
        cin >> arr[i];

    vector<ll> leftSums, rightSums;
    makeSums(0,N/2-1,arr,leftSums,0);
    makeSums(N/2,N-1,arr,rightSums,0);

    sort(rightSums.begin(), rightSums.end());

    int leftSumsSize = leftSums.size(), sol = 0;
    for(int i=0; i<leftSumsSize; i++){
        ll restC = C - leftSums[i];
        sol += upper_bound(rightSums.begin(),rightSums.end(),restC) - rightSums.begin();
    }
    cout << sol;

    return 0;
}

