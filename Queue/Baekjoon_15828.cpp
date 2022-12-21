#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;

    int buffer_size, tmp, size;
    cin >> buffer_size;
    queue<int> buffer;

    while (1)
    {
        cin >> tmp;
        if (tmp == -1)
            break;
        else if (tmp == 0)
            buffer.pop();
        else if (buffer.size() < buffer_size)
            buffer.push(tmp);
    }

    size = buffer.size();
    if (size == 0)
        cout << "empty" << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << buffer.front() << "\n";
        buffer.pop();
    }
}