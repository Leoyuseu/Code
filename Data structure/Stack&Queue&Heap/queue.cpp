#include<iostream>
#include<string>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct queue
{
	node *first, *rear;
};

void print(queue *HQ)
{
	node *s;
	s = HQ->first;
	if (HQ->rear == NULL)
		cout << "no data" << endl;
	else
	{
		if (s != HQ->rear)
		{
			cout << s->data << ",";
			s = s->next;
		}
	}
}

queue *insert(queue *HQ , int x)
{
	node *s = new node;
	s->data = x;
	s->next = NULL;
	if (HQ->rear == NULL)
	{
		HQ->first = s;
		HQ->rear = s;
	}
	else
	{
		HQ->rear->next = s;
		HQ->rear = s;
	}
	return HQ;
}

queue *del(queue *HQ)
{
	if (HQ->first = NULL)
		cout << "error" << endl;
	else
	{
		if (HQ->first == HQ->rear)
		{
			HQ->first = NULL;
			HQ->rear = NULL;
		}
		else
		{
			HQ->first = HQ->first->next;
		}
	}
	return HQ;
}



int main()
{
	queue *Q=new queue();
	for (int i = 0; i < 10; ++i)
		insert(Q, i);
	print(Q);

	for (int i = 0; i < 5; ++i)
		del(Q);
	print(Q);
}