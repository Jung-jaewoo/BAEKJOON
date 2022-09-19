#include <iostream>
#include <algorithm>
//#include <vector>
//#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e10
#define ll long long
using namespace std;

int* input(int* n, int* x);
void solution(int* a, int n, int x);

int main(){
    fastio;
    int* a;
    int n, x;
    a = input(&n, &x);
    solution(a, n, x);
    return 0;
}

int* input(int* n, int* x)
{
    cin >> *n;
    int* a;
    a = new int[*n];
    for(int i=0; i<*n; i++){
        cin >> a[i];
    }
    cin >> *x;
    return a;
}

void solution(int* a, int n, int x)
{
    if(n == 1){
        cout << 0;
        return;
    }
    sort(a,a+n); // 정렬
    int sol = 0;
    int ptr1=0, ptr2=n-1, sum;
    while(ptr1<ptr2){
        sum = a[ptr1] + a[ptr2];
        if(sum<x){
            ptr1++;
        }
        else if(sum>x){
            ptr2--;
        }
        else{
            sol++;
            ptr1++, ptr2--;
        }
    }
    cout << sol;
}