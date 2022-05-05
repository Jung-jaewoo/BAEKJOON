#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
int alphanum[26];
int itcanbepalindrome(void);
void printpepalindrome(int flag);

int main(){
	string tmp;
	cin >> tmp;
	for(int i=0; i<tmp.size();i++)
		alphanum[tmp[i]-'A']++;
	printpepalindrome(itcanbepalindrome());
	return 0;
}

int itcanbepalindrome(void){
	int flag = 0;
	for(int i=0; i<26; i++){
		if(alphanum[i]%2==1)
			flag++;
	}
	if(flag>1){
		return 0;
	}
	else
		return 1;
}

void printpepalindrome(int flag){
	if(flag){
		for(int i=0; i<26; i++){
			for(int j=0; j<alphanum[i]/2; j++)
				printf("%c",'A' + i);
		}
		for(int i=0; i<26; i++){
			if(alphanum[i]%2==1){
				printf("%c",'A' + i);
			}
		}
		for(int i=25; i>=0; i--){
			for(int j=0; j<alphanum[i]/2; j++)
					printf("%c",'A' + i);
		}	
	}
	else{
		cout << "I'm Sorry Hansoo";
	}
}