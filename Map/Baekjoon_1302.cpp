#include <iostream>
#include <algorithm>
#include <map>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
	int result =0, n;
	cin >> n;
	map <string, int> m;
	string tmp;
	for(int i=0; i<n; i++){
		cin >> tmp;
		m[tmp]++;
	}
	for(auto i = m.begin(); i!=m.end(); i++)
		result = max(result, i->second);
	for(auto i = m.begin(); i!=m.end(); i++){
		if(result == i->second){
			cout << i->first;		
			return 0;
		}
	}
	return 0;
}