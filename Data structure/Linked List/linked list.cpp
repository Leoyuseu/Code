#include <iostream>
#include<string>
using namespace std;
//使用linkedlist Class封装
//定义节点
typedef struct student
{
	int data;
	struct student *next;
}node;

//单链表的建立
node *creat()
{
	node *head, *p, *s;
	int x, cycle = 1;
	head = (node*)malloc(sizeof(node));
	p = head;
	while (cycle)
	{
		cout << "please input the data:" ;
		cin >> x ;
		if (x != 0)
		{
			s = (node*)malloc(sizeof(node));
			s->data = x;
			cout <<s->data<< endl;
			p->next = s;
			p = s;			
		}
		else cycle = 0;
	}
	head = head->next;
	p->next = NULL;
	cout << head->data << endl;
	return(head);
}

//单链表的测长
int length(node *head)
{
	int n = 0;
	node *p;
	p = head;
	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	return n;
}

//单链表的打印
void print(node *head)
{
	node *p;
	int n;
	n = length(head);
	cout << "those " << n << " records are:";
	p = head;
	if (head != NULL)
	{
		while (p != NULL)
		{
			cout << p->data << "  ";
			p = p->next;
		}
	}
	cout << endl;
}

//单链表删除节点
node *del(node* head, int num,int &flag)   //如果num是head->data的话，会出现p2未定义的情况
{
	node *p1, *p2=0;
	p1 = head;
	if (p1 == NULL)
	{
		cout<<"no contents.";
	}
	if (num == p1->data)
	{
		head = p1->next;
		free(p1);
	}
	else
	{
		while (num != p1->data&&p1->next != NULL)
		{
		p2 = p1;
		p1 = p1->next;
		}
		if (num==p1->data)
		{
			p2->next = p1->next;
			free(p1);
		}
	}
//	else
	//{
		//flag = 0;              //处理只能删除一次
//	}
	return head;
}

//单链表的插入
node *insert(node* head,int num)              //head头节点之前插入无效
{
	node *p0, *p1, *p2=0;
	p1 = head;
	p0 = (node *)malloc(sizeof(node));
	p0->data = num;
	while (p0->data > p1->data&&p1->data != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p0->data <= p1->data)
	{
		if (head == p1)
		{
			p0->next = p1;
			head = p0;
		}
		else
		{
			p2->next = p0;
			p0->next = p1;
		}
	}
	else
	{
		p1->next = p0;
		p0->next = NULL;
	}
	return head;
}

//单链表排序
node *sort(node *head)
{
	node *p;
	int n;
	int temp;
	n=length(head);
	if(head->next=NULL)
		return head;
	p=head;
	for(int j=1;j<n;++j)
	{
		p=head;
		for(int i=0;i<n-j;++i)
		{
			if(p->data>p->next->data)
			{
				temp=p->data;
				p->data=p->next->data;
				p->next->data=temp;
			}
		p=p->next;
		}
	}
	return head;
}

//单链表逆置
node *reverse(node *head)
{
	node *p1,*p2,*p3;
	
	if (head == NULL || head->next == NULL)
		return head;
	p1 = head;
	p2 = p1->next;
	while (p2)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}

	head->next = NULL;
	head = p1;
	return head;
}

//遍历一次找出单链表的中间节点快慢节点
void searchmid(node* head)
{
	node *temp = head;
	while (head->next->next != NULL)
	{
		head = head->next->next;
		temp = temp->next;
		if(!head->next) break;  
	}
	cout << "mid number is:" << temp->data<<endl;
}

int main()
{
	node *head;
	int flag = 1;
	int del_num, insert_num;
	
	head = creat();
	int len = length(head);
	cout <<"the length of the records is:"<< len<<endl;
	print(head);

	cout << "input the num you want to delete:";
	cin >> del_num;
	cout << endl;
	while(flag)
	{
		del(head,del_num,flag);   //num出现多次删除
	}
	print(head);

	cout << "input the num you want to insert:";
	cin >> insert_num;
	cout << endl;
	insert(head,insert_num);
	print(head);

	return 0;
}


