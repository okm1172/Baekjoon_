#include <iostream>

using namespace std;
//포인터를 사용할땐 초기값이나 초기화값을 확실하게 명시 해줘야 segfault 오류가 뜨지 않는다.
//이거땜에 시간 3시간 소요했음..

class Node
{
public:
	int data;
	Node* next;

	Node()
	{
		this->data = 0;
		this->next = NULL;
	}
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
class LinkedList
{
public:
	Node* head=NULL;//이게 링크드리스트의 핵심
	int size, ccnt = 0;
	void insertdata(int);
	void deletedata();
	void rightdata();
	void leftdata();
	void finddata(int);
};
void LinkedList::insertdata(int data2)
{
	Node* newnode = new Node(data2);
	if (head == NULL)
	{
		head = newnode;
		return;
	}

	Node* a = head;
	while (a->next != NULL)
	{
		a = a->next;
	}
	a->next = newnode;
	return;
}
void LinkedList::finddata(int find)
{
	Node* a = head;
	if (a->data == find)
	{
		deletedata();
		return;
	}
	int cnt = 1;
	while (1)
	{
		if (a->data == find)
		{
			if (size+2 < 2*cnt)
			{
				while (1)
				{
					ccnt++;
					cnt++;
					rightdata();
					if (cnt == size+1)
					{
						deletedata();
						break;
					}
				}
			}
			else
			{
				while(1)
				{
					ccnt++;
					cnt--;
					leftdata();
					if (cnt == 1)
					{
						deletedata();
						break;
					}
				}
			}
			break;
		}
		a = a->next;
		cnt++;
	}
	return;
}
void LinkedList::deletedata()
{
	if (head == NULL)
	{
		cout << "empty!";
		return;
	}
	Node* a = head;
	if (a->next == NULL)
	{
		head == NULL;
		return;
	}
	Node* b = a->next;
	head = b;
	size--;
	free(a);
	return;
}
void LinkedList::rightdata()
{
	Node* a = head;
	Node* b = head;
	if (b->next == NULL)
		return;
	while (1)
	{
		if (b->next->next == NULL)
		{
			b->next->next = a;
			head = b->next;
			b->next = NULL;
			break;
		}
		b = b->next;
	}
	return;
}
void LinkedList::leftdata()
{
	Node* a = head;
	Node* b = head;
	if (b->next == NULL)
		return;
	while (1)
	{
		if (b->next == NULL)
		{
			b->next = a;
			head = a->next;
			a->next = NULL;
			break;
		}
		b = b->next;
	}
	return;
}
int main()
{
	int n, m;
	int ddata;
	cin >> n >> m;
	LinkedList list;
	list.size = n;
	for (int i = 1; i <= n; i++)
	{
		list.insertdata(i);
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> ddata;
		list.finddata(ddata);
	}
	cout << list.ccnt;
	return 0;
}