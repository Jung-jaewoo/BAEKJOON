#include <iostream>
#include <stack>
#include <string>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void makePostfix(queue<char>& infix);

int main()
{
    fastio;
    
    string infix;
    cin >> infix;
    
    queue<char> q;
    for(int i=0; i<infix.size(); i++)
        q.push(infix[i]);

    makePostfix(q);
    
    return 0;
}

void makePostfix(queue<char>& infix)
{
    stack<char> s;
    
    while(infix.size()){
        char c = infix.front();

        if('A' <= c && c <= 'Z'){
            cout << infix.front();
            infix.pop();
        }
        else if(c =='('){
            infix.pop();
            makePostfix(infix);
        }
        else if(c == ')'){
            infix.pop();
            while(s.size()!=0){
                cout << s.top();
                s.pop();
            }
            return;
        }
        else if(c == '+' || c == '-'){
            while(s.size()!=0){
                cout << s.top();
                s.pop();
            }
            s.push(c);
            infix.pop();
        }
        else{ // *,/
            while(s.size()!=0 && (s.top()=='*' || s.top()=='/')){
                cout << s.top();
                s.pop();
            }
            s.push(c);
            infix.pop();
        }
    }

    while(s.size()!=0){
        cout << s.top();
        s.pop();
    }
        
}
