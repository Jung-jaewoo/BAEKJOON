#include <iostream>
#include <algorithm>
using namespace std;


void input(int* Nptr, int** x, int** y);
void setPrefixSum(int* arr);
void setRectangle(int* arr, int x, int y);
void setRectangles(int* arr, int* x, int* y, int N);
void findMaxRectangleArea(int* arr);

int main()
{
    int N;
    int *x, *y;
    int arr[101*101];
    fill(arr, arr+101*101, 0);
    input(&N,&x,&y);
    setRectangles(arr,x,y,N);
    setPrefixSum(arr);
    findMaxRectangleArea(arr);
    return 0;
}

void input(int* Nptr, int** x, int** y)
{
    cin >> *Nptr;
    *x = new int[*Nptr];
    *y = new int[*Nptr];
    for(int i=0; i<*Nptr; i++){
        cin >> (*x)[i] >> (*y)[i];
    }
}

void setPrefixSum(int* arr)
{
    for(int i=100; i>=0; i--){
        for(int j=1; j<101; j++){
            if(arr[i*101+j]==1)
                arr[i*101+j] = arr[(i+1)*101+j] + 1;
        }
    }
}

void setRectangle(int* arr, int x, int y)
{
    for(int i=x; i<x+10; i++){
        for(int j=y; j<y+10; j++){
            arr[101*i+j] = 1;
        }
    }
}

void setRectangles(int* arr, int* x, int* y, int N)
{
    for(int i = 0; i<N; i++){
        setRectangle(arr,x[i],y[i]);
    }
}

void findMaxRectangleArea(int* arr)
{
    int answer = 0;
    for(int i=100; i>=1; i--){
        for(int j=1; j<101; j++){
            int h = 100;
            for(int k=j; k<=100; k++){
                h = min(arr[i*101+k], h);
                if(h==0)
                    break;
                answer = max(answer, h*(k-j+1));
            }
        }
    }
    cout << answer << endl;
}