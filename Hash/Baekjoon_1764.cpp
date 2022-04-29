#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
map<string, int> map1;
vector<string> res;
int N, M;
bool compare(string& str1, string& str2)
{
	int len = min(str1.size(), str2.size());
	if (str1[0] == str2[0])
	{
		for (int i = 1; i < len; i++)
		{
			if (str1[i] == str2[i]) continue;
			return str1[i] < str2[i];
		}
	}
	else {
		return str1[0] < str2[0];
	}
	return str1.size() < str2.size();
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		string input;
		cin >> input;
		map1.insert({ input,1 });
	}
	for (int i = 0; i < M; i++) {
		string input;
		cin >> input;
		if (map1[input] == 1)
		{
			res.push_back(input);
		}
	}
	sort(res.begin(), res.end(), compare);
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << "\n";
	return 0;
}




