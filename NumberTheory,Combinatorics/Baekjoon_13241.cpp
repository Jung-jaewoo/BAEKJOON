#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    long long A, B, oA, oB, gcd;
    cin >> oA >> oB;
    A = oA;
    B = oB;

    while(1){
        if(A<B)
            swap(A,B);
        if(A%B==0){
            gcd = B;
            break;
        }
        A = A%B;
    }
    
    cout << oA*oB/gcd;

    return 0;
}