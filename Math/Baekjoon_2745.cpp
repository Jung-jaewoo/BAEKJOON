#include <iostream>
#include <string>
#include <cmath>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;

    string num;
    int base;
    cin >> num >> base;

    int cnt = num.length(), i = 0, ans = 0, place_value;
    while(cnt--)
    {
        place_value = num[i] - '0';
        if(place_value>=0 && place_value<=9){
            ans += place_value*pow(base,cnt);
        }
        else{
            place_value -= 7; // 아스키코드 : A 65, '0' 48
            ans += place_value*pow(base,cnt);
        }
        i++;
    }

    cout << ans;
    return 0;
}