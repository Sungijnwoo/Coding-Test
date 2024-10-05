#include <iostream>
using namespace std;

class Node
{
public:
	Node(){}

	Node(char InValue)
	{
		value = InValue;
	}

	void SetLeft(Node* InLeft)
	{
		left = InLeft;
	}

	void SetRight(Node* InRight)
	{
		right = InRight;
	}

	char GetValue() { return value; }

	Node* GetLeft() { return left; }
	Node* GetRight() { return right; }
private:
	char value;
	Node* left;
	Node* right;
};

class Tree
{
public:
	Tree(){}

	Tree(char InValue)
	{
		root = AddNode(InValue);
	}

	Node* AddNode(char InValue)
	{
		nodes[nodeCount] = new Node(InValue);
		++nodeCount;
		return nodes[nodeCount - 1];
	}

	Node* GetRoot() { return root; }

	Node* GetNode(char InChar)
	{
		for (int i = 0; i < nodeCount; ++i)
		{
			if (nodes[i]->GetValue() == InChar)
			{
				return nodes[i];
			}
		}

		return AddNode(InChar);
		
	}

	void PreOrder(Node* node)
	{
		if (node==nullptr)
			return;
		cout << node->GetValue();
		PreOrder(node->GetLeft());
		PreOrder(node->GetRight());
	}

	void InOrder(Node* node)
	{
		if (node == nullptr)
			return;
		InOrder(node->GetLeft());
		cout << node->GetValue();
		InOrder(node->GetRight());
	}

	void PostOrder(Node* node)
	{
		if (node == nullptr)
			return;
		PostOrder(node->GetLeft());
		PostOrder(node->GetRight());
		cout << node->GetValue();
	}
private:
	Node* nodes[26];

	int nodeCount = 0;

	Node* root;
};

int main()
{
	int N;
	cin >> N;

	Tree* tree = new Tree('A');

	for (int i = 0; i < N; ++i)
	{
		char parent, left, right;
		cin >> parent >> left >> right;
		if (parent == 'A')
		{
			Node* root = tree->GetRoot();
			if(left!='.')
				root->SetLeft(tree->AddNode(left));
			if(right!='.')
				root->SetRight(tree->AddNode(right));
		}
		else
		{
			Node* parentNode = tree->GetNode(parent);
			if (left != '.')
				parentNode->SetLeft(tree->AddNode(left));
			if (right != '.')
				parentNode->SetRight(tree->AddNode(right));
		}
	}

	tree->PreOrder(tree->GetRoot());
	cout << "\n";
	tree->InOrder(tree->GetRoot());
	cout << "\n";
	tree->PostOrder(tree->GetRoot());
}