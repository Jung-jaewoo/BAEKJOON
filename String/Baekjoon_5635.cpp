#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef struct{
	string name;
	int year, month, day;
}student;

int main()
{
	int n, i = 0;
	cin >> n;
	student* students;
	students = new student[n];
	int maxindex=0,minindex=0,tmp;
	cin >> students[i].name >> students[i].day >> students[i].month >> students[i].year;
	for(i=1; i<n; i++){
		cin >> students[i].name >> students[i].day >> students[i].month >> students[i].year;
		if(students[maxindex].year > students[i].year)
			maxindex = i;
		else if(students[maxindex].year==students[i].year){
			if(students[maxindex].month > students[i].month){
				maxindex =i;
			}
			else if(students[maxindex].month==students[i].month){
				if(students[maxindex].day > students[i].day)
					maxindex = i;
			}
		}	
		else if(students[minindex].year < students[i].year){
			minindex = i;
		}
		else if(students[minindex].year==students[i].year){
			if(students[minindex].month < students[i].month){
				minindex =i;
			}
			else if(students[minindex].month==students[i].month){
				if(students[minindex].day < students[i].day)
					minindex = i;
			}
		}
	}	
	cout << students[minindex].name << "\n";
	cout << students[maxindex].name;
	return 0;
}