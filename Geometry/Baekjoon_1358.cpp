#include <iostream>
#include <cmath>
using namespace std;

int W,H,X,Y,P,x,y,sol;

void solution();

int main()
{
    cin >> W >> H >> X >> Y >> P;
    while(P--){
        cin >> x >> y;
        solution();    
    }
    cout << sol;
    return 0;
}

void solution()
{
    if(pow(X-x,2)+pow(Y+H/2-y,2) <= (H/2)*(H/2) || pow(X+W-x,2)+pow(Y+H/2-y,2) <= (H/2)*(H/2))
        sol++;
    else if(X<=x && x<=X+W && Y<=y && y<=Y+H)
        sol++;
}