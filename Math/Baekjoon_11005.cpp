#include <iostream>
#include <string>
#include <cmath>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;

    int num, base, cnt = 0;
    cin >> num >> base;
    
    while(pow(base,cnt++)<=num);
    cnt-=2;

    string ans;
    int place_value;

    while(cnt>=0){ // 각자리 수 만큼
        place_value = 0;
        while(num >= ++place_value*(int)pow(base,cnt));
        place_value-=1;
        
        num -= place_value*(int)pow(base,cnt);

        if(place_value>=10)
            ans.push_back(place_value + 55); // A 65
        else
            ans.push_back(place_value + 48); //'0' 48
        cnt--;
    }

    cout << ans;
    return 0;
}