#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	string* input;
	input = new string[n];
	for(int i=0; i<n; i++)
		cin >> input[i];
	string sol;
	int num = 0;
	vector <int> initiate;
	for(int i=0; i<m; i++){
		int alpha[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		int max = 0;
		for(int j=0; j<n; j++){
			alpha[input[j][i]-'A']++;
			if(alpha[input[j][i]-'A']>alpha[max]) max = input[j][i]-'A';
			else if(alpha[input[j][i]-'A']==alpha[max]) max = min(input[j][i]-'A',max);
		}
		num += n - alpha[max];
		sol.push_back(char(max+65));
	}
	cout << sol << "\n" << num;
	return 0;
}