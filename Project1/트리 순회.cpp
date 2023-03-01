#include <iostream>

using namespace std;
//선생님 트리는 구조체 사용합시다 클래스 쓴다고 깝치지말고
struct Tree
{
	char data;
	Tree* left=NULL, * right=NULL;
};

void wjs(Tree* top)
{
	cout << top->data;
	if(top->left!=NULL)
	wjs(top->left);
	if(top->right!=NULL)
	wjs(top->right);
}
void wnd(Tree* top)
{
	if(top->left!=NULL)
	wnd(top->left);
	cout << top->data;
	if(top->right!=NULL)
	wnd(top->right);
}
void gn(Tree* top)
{
	if (top->left != NULL)
		gn(top->left);
	if (top->right != NULL)
		gn(top->right);
	cout << top->data;
}
int main()
{
	int n;
	cin >> n;
	Tree* tree = new Tree[30];
	for (int i = 1; i <= n; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		tree[a - 'A'].data = a;
		if (b != '.')
		{
			tree[b - 'A'].data = b;
			tree[a - 'A'].left = &tree[b - 'A'];
		}
		if (c != '.')
		{
			tree[c - 'A'].data = c;
			tree[a - 'A'].right = &tree[c - 'A'];
		}
	}
	wjs(&tree[0]);
	cout << endl;
	wnd(&tree[0]);
	cout << endl;
	gn(&tree[0]);
	return 0;
}