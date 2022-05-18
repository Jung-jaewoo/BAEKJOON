#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int spx, spy, epx, epy, cx, cy, r, d, n, T;
    cin >> T;
    while(T--){
        int sol = 0;
        cin >> spx >> spy >> epx >> epy;
        cin >> n;
        while(n--){
            cin >> cx >> cy >> r;
            if((pow(spx-cx,2)+pow(spy-cy,2)>pow(r,2)&&pow(epx-cx,2)+pow(epy-cy,2)<pow(r,2))||(pow(spx-cx,2)+pow(spy-cy,2)<pow(r,2)&&pow(epx-cx,2)+pow(epy-cy,2)>pow(r,2)))
                sol++;
        }
        cout << sol << "\n";
    }
    return 0;
}