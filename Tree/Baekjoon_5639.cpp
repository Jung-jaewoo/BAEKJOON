#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void makePostOrder(int(&preorder)[10001], int& n, int& index, int parent);

int main()
{
    fastio;

    int preorder[10001], n = 0;

    while (!cin.eof()) {
        cin >> preorder[n++];
    }
    n -= 1;
    
    int index = 0;
    makePostOrder(preorder, n, index, 1e6);

    return 0;
}

void makePostOrder(int(&preorder)[10001], int& n, int& index, int right)
{
    if (index > n - 1) return;

    int root = preorder[index];

    if (preorder[index + 1] < root) {
        index++;
        makePostOrder(preorder, n, index, root);
    }
    if (preorder[index + 1] > root && preorder[index + 1] < right) {
        index++;
        makePostOrder(preorder, n, index, right);
    }
    cout << root << "\n";
}