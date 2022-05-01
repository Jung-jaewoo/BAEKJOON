#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void recursion(int n, int k);

int main()
{
    fastio;
    int n;
    cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    recursion(n, 0);
    return 0;
}

void recursion(int n, int k) 
{
    for (int i = 0; i < k; i++) cout << "____";
    cout << "\"����Լ��� ������?\"\n";
    for (int i = 0; i < k; i++) cout << "____";
    if (n == k) cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    else {
        cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
        for (int i = 0; i < k; i++) cout << "____";
        cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
        for (int i = 0; i < k; i++) cout << "____";
        cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
        recursion(n, k + 1);
    }
    for (int i = 0; i < k; i++) cout << "____";
    cout << "��� �亯�Ͽ���.\n";
}