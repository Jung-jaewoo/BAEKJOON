#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
	fastio;
	string input;
	getline(cin, input);
	char ucpc[4] = {'U','C','P','C'};
	int inputSize = input.size();
	int cnt = 0;
	for(int i=0; i<inputSize; i++){
		if(ucpc[cnt]==input[i]){
			cnt++;
		}
	}
	if(cnt>=4) cout << "I love UCPC";
	else cout << "I hate UCPC";
	return 0;
}