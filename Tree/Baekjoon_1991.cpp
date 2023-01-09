#include <iostream>
#include <vector>
using namespace std;

typedef struct node{
    char name;
    struct node* leftchild, *rightchild;
}node;

node* makeNode(char name);
node* findPosition(char name, node* current);
void preVisit(node* current);
void inVisit(node* current);
void postVisit(node* current);

int main()
{
    int N;
    cin >> N;

    node* root = makeNode('A');
    for(int i=0; i<N; i++){
        char parent, child1, child2;
        cin >> parent >> child1 >> child2;

        node* parentNode = findPosition(parent, root);
        if(child1 != '.'){
            parentNode->leftchild = makeNode(child1);
        }
        if(child2 != '.'){
            parentNode->rightchild = makeNode(child2);
        }
    }

    preVisit(root);
    cout << "\n";
    inVisit(root);
    cout << "\n";
    postVisit(root);

    return 0;
}

node* makeNode(char name)
{
    node* newNode = new node;
    newNode->name = name;
    newNode->leftchild = nullptr;
    newNode->rightchild = nullptr;
    return newNode;
}

node* findPosition(char name, node* current)
{
    if(current == nullptr)
        return nullptr;
    if(current->name == name){
        return current;
    }
    node* tmp = findPosition(name, current->leftchild);
    if(tmp!=nullptr)
        return tmp;
    tmp = findPosition(name, current->rightchild);
    if(tmp!=nullptr)
        return tmp;
    return nullptr;
}

void preVisit(node* current)
{
    if(current==nullptr)
        return;
    cout << current->name;
    preVisit(current->leftchild);
    preVisit(current->rightchild);
}

void inVisit(node* current)
{
    if(current==nullptr)
        return;
    
    inVisit(current->leftchild);
    cout << current->name;
    inVisit(current->rightchild);
}

void postVisit(node* current)
{
    if(current==nullptr)
        return;
    
    postVisit(current->leftchild);
    postVisit(current->rightchild);
    cout << current->name;
}