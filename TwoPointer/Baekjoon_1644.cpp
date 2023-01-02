#include <iostream>
#include <vector>
using namespace std;

vector<int> makePrimeNumbers(bool* arr, int N);
void findSolution(vector<int> vecArr, int N);

int main()
{
    int N;
    cin >> N;

    bool *arr;
    arr = new bool[N+1];

    vector<int> vecArr = makePrimeNumbers(arr, N);
    findSolution(vecArr,N);

    return 0;
}

vector<int> makePrimeNumbers(bool* arr, int N)
{
    fill(arr,arr+N+1,true);

    arr[0] = arr[1] = false;
    for(int i=2; i*i<=N; i++){
        for(int j=i*i; j<=N; j+=i){
            arr[j] = false;
        }
    }

    vector<int> vecArr;
    vecArr.push_back(0);

    int sum = 0;
    for(int i=2; i<=N; i++){
        if(arr[i]==true){
            sum += i;
            vecArr.push_back(sum);
        }
    }

    delete[] arr;
    return vecArr;
}

void findSolution(vector<int> vecArr, int N)
{
    int ptr1=0, ptr2=0, sol=0;
    int size = vecArr.size();

    while(ptr1<=ptr2 && ptr2<size){
        if(vecArr[ptr2]-vecArr[ptr1]>N)
            ptr1++;
        else if(vecArr[ptr2]-vecArr[ptr1]<N)
            ptr2++;
        else{
            sol++;
            ptr2++;
        }
    }

    cout << sol << endl;
}