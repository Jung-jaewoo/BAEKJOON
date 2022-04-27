#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    string tmp;
    string input;
    vector <string> arr;
    vector <int> havetoreverse;
    getline(cin, tmp);
    int tmp_size = tmp.size();
    int start_flag = 0, end_flag = 0, tag_flag;
    int size = 0;
    for(int i=0; i<tmp_size; i++){
        if(tmp[i]=='<') {
            if(input.size()!=0){
                arr.push_back(input);
                input.clear();
                havetoreverse.push_back(size);
                size++;
            }
            start_flag = 1;
        }
        else if(start_flag == 1 && tmp[i] == '>') {
            end_flag = 1;
            tag_flag = 1;
        }
        else if(start_flag==0 && tmp[i]== ' ') end_flag = 1;
        input.push_back(tmp[i]);
        if(end_flag) {
            if(tag_flag){
                arr.push_back(input);
                input.clear();
                tag_flag =0;
                start_flag = 0;
                end_flag = 0;
            }
            else{
                arr.push_back(input);
                input.clear();
                havetoreverse.push_back(size);
                start_flag = 0;
                end_flag = 0;
            }
            size++;
        }
    }
    if(input.size()!=0){
        arr.push_back(input);
        havetoreverse.push_back(size);
        size++;
    }
    for(int i=0; i<havetoreverse.size(); i++){
        int index= havetoreverse[i];
        if(arr[index][arr[index].size()-1]==' ') reverse(arr[index].begin(),arr[index].end()-1);
        else reverse(arr[index].begin(),arr[index].end());
    }
    for(int i=0; i<arr.size(); i++){
        cout << arr[i];
    }
    return 0;
}