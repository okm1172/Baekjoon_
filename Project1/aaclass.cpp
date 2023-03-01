/*
22
Print
Append 6
Append 8
Append 3
Delete 5
Append 7
Delete 2
Print_reverse
Print
Append 2
Update 2 7
Delete 7
Update 3 2
Delete 4
Delete 1
Print_reverse
Append 10
Print
Print_reverse
Update 7 1
Delete 3
Print
*/
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int data=0;
	Node* next=NULL;
	Node* pre = NULL;
	Node(int data)
	{
		this->next = NULL;
		this->pre = NULL;
		this->data = data;
	}
	Node()
	{
		this->next = NULL;
		this->pre = NULL;
		this->data = 0;
	}
};
class List
{
public:
	int listcnt = 0;
	Node* head = NULL;
	Node* tail = NULL;
	void print();
	void append(int);
	void del(int);
	void insert(int, int);
	void pri();
	//void sum();
	void min();
};
void List::append(int data)
{
	Node* newnode = new Node(data);
	listcnt++;
	if (head == NULL)
	{
		head = newnode;
		tail = newnode;
		print();
		return;
	}
	Node* a = head;
	while (a->next != NULL)
	{
		a = a->next;
	}
	a->next = newnode;
	tail = newnode;
	newnode->pre = a;
	print();
}
void List::del(int i)
{
	Node* a = head;
	Node* b = tail;
	int cnt=0;
	if (listcnt <= i)
	{
		cout << "-1" << endl;
		return;
	}
	if (i == 0)
	{
		cout << a->data << endl;
		head = a->next;
		head->pre = NULL;
	}
	else if (i == listcnt-1)
	{
		cout << b->data << endl;
		tail = b->pre;
		tail->next = NULL;
	}
	else
	while (1)
	{
		if (cnt == i-1)
		{
			cout << a->next->data<<endl;
			a->next->next->pre = a;
			a->next = a->next->next;
			break;
		}
		cnt++;
		a = a->next;
	}
	listcnt--;
}
void List::insert(int i, int dat)
{
	Node* a = head;
	int cnt = 0;
	while (1)
	{
		if (a == NULL&&cnt==0)
		{
			cout << "Not found" << endl;
			return;
		}
		else if (a == NULL && cnt != 0)
		{
			break;
		}
		if (a->data == i)
		{
			cnt++;
			a->data = dat;
		}
		a = a->next;
	}
	print();
}
void List::pri()
{
	Node* a = tail;
	if (tail == NULL)
	{
		cout << "empty" << endl;
		return;
	}
	while (a != NULL)
	{
		cout << a->data<<" ";
		a = a->pre;
	}
	cout << endl;
}
void List::print()
{
	Node* a = head;
	if (head == NULL)
	{
		cout << "empty"<<endl;
		return;
	}
	while (1)
	{
		if (a == NULL)
			break;
		cout << a->data << " ";
		a = a->next;
	}
	cout << endl;
}
int main()
{
	int n;
	int i;
	string a;
	List list;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a;
		if (a[0] == 'P' && a[5] == '_')
		{
			list.pri();
		}
		else if (a[0] == 'A')
		{
			int aa;
			cin >> aa;
			list.append(aa);
		}
		else if (a[0] == 'D')
		{
			int aa;
			cin >> aa;
			list.del(aa);
		}
		else if (a[0] == 'P')
		{
			list.print();
		}
		else
		{
			int aa, bb;
			cin >> aa >> bb;
			list.insert(aa, bb);
		}
	}
	return 0;
}