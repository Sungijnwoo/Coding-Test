#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;
	Node(int inValue)
	{
		value = inValue; 
	}
};


void postOrder(Node* node)
{
	if(node->left)
		postOrder(node->left);
	if(node->right)
		postOrder(node->right);
	cout << node->value << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tmp;

	cin >> tmp;
	Node* root = new Node(tmp);
	Node* current; 
	Node* par;
	while (cin >> tmp)
	{
		if (tmp == EOF)
			break;
		current = root; 

		while (current != nullptr)
		{
			par = current; 
			if (current->value < tmp)
			{
				current = current->right;
			}
			else
			{
				current = current->left;
			}
		}
		if (par->value < tmp)
		{
			par->right = new Node(tmp);
		}
		else
		{
			par->left = new Node(tmp);
		}
	}

	postOrder(root);
}