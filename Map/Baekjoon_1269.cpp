#include <iostream>
#include <vector>
#include <map>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
	fastio;
	int a,b,tmp,sol=0;
	map <int,int> ma;
	map <int,int> mb;
	cin >> a >> b;
	for(int i=0; i<a; i++){
		cin >> tmp;
		ma.insert({tmp,1});
	}
	for(int i=0; i<b; i++){
		cin >> tmp;
		mb.insert({tmp,1});
		if(ma.find(tmp)==ma.end())	sol++;
	}
	map <int,int>::iterator iter;
	for(iter=ma.begin(); iter!=ma.end(); iter++){
		if(mb.find(iter->first)==mb.end()) sol++;
	}
	cout << sol;
	return 0;
}