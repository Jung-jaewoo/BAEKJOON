#include <iostream>
#include <string>
#include <map>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
	fastio;
	map <string, int> m;
	string tmp, subtmp;
	int sol=0;
	cin >> tmp;
	int tmpSize = tmp.size();
	for(int i=0; i<tmpSize; i++){
		for(int j=i; j<tmpSize; j++){
			subtmp.push_back(tmp[j]);
			if(m.find(subtmp)==m.end()) {
				m.insert({subtmp,1});
				sol++;
			}
		}
		subtmp.clear();
	}
	cout << sol;
	return 0;
}