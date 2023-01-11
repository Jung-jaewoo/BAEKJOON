#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;


void inputOrder(vector<int>& order, int n);
void memoRootPosition(vector<int>& rootPosition, vector<int>& inorder, int n);
void findRoot(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, vector<int>& rootPosition);

int main()
{
    fastio;

    int n;
    cin >> n;

    vector<int> inorder;
    vector<int> postorder;
    vector<int> rootPosition;
    inorder.resize(n);
    postorder.resize(n);
    rootPosition.resize(n+1);

    inputOrder(inorder, n);
    inputOrder(postorder, n);
    memoRootPosition(rootPosition, inorder, n);
    
    findRoot(inorder, 0, n-1, postorder, 0, n-1, rootPosition);

    return 0;
}

void inputOrder(vector<int>& order, int n)
{
    for(int i=0; i<n; i++)
        cin >> order[i];
}

void memoRootPosition(vector<int>& rootPosition, vector<int>& inorder, int n)
{
    for(int i=0; i<n; i++)
        rootPosition[inorder[i]] = i;
}

void findRoot(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, vector<int>& rootPosition)
{
    if(inEnd<inStart) return;

    cout << postorder[postEnd] << " ";
    
    
    int leftInStart = inStart, 
        leftInEnd = rootPosition[postorder[postEnd]] - 1, 
        rightInStart = rootPosition[postorder[postEnd]] + 1, 
        rightInEnd = inEnd;

    findRoot(inorder, leftInStart, leftInEnd, postorder, postStart, postStart + leftInEnd - leftInStart, rootPosition);  // root 기준 왼쪽
    findRoot(inorder, rightInStart, rightInEnd, postorder, postStart + leftInEnd - leftInStart + 1, postEnd - 1, rootPosition);   // root 기준 오른쪽
}
