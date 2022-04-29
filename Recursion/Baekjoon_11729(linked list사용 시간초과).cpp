#include <iostream>
using namespace std;
struct load {
	int a, b;
	struct load *link;
};
struct load *hanoi_move_front;
int sum = 0;
void hanoi_insert(int a, int b);
void hanoi(int a, int b, int c, int n);

int main()
{	
	int N;
	cin >> N;
	hanoi(1, 3, 2, N);
	printf("%d\n", sum);

	struct load *temp;
	temp = hanoi_move_front;
	while (temp!=NULL)
	{
		printf("%d %d\n", temp->a, temp->b);
		temp = temp->link;
	}
	return 0;
}

void hanoi_insert(int a, int b)
{
	struct load *ip;
	ip = (struct load*)malloc(sizeof(struct load));
	ip->a = a;
	ip->b = b;
	ip->link = NULL;

	struct load* temp;

	temp = hanoi_move_front;
	if (temp == NULL)
		hanoi_move_front = ip;
	else
	{
		while (1)
		{
			if (temp->link != NULL)
				temp = temp->link;
			else
				break;
		}
		temp->link = ip;
	}
}

void hanoi(int a, int b, int c, int n)
{
	sum++;
	if (n == 1)
	{
		hanoi_insert(a, b);
	}
	else
	{
		hanoi(a, c, b, n - 1);
		hanoi_insert(a, b);
		hanoi(c, b, a, n - 1);
	}
}