#include <iostream>
#include <map>
#include <string>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    map <string, int> m;
    string tmp;
    int sum = 0;
    while(getline(cin,tmp)) {
        m[tmp]++;
        sum++;
    }
    cout.setf(ios::fixed);
    cout.precision(4);
    for (auto iter = m.begin(); iter!=m.end(); iter++) {
        cout << iter->first << " " << (double)iter->second / sum * 100 << "\n";
    }
    return 0;
}