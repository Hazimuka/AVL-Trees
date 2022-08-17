using namespace std;
#include <iostream>


class Node
{
public:
	int key;
	Node* left;
	Node* right;
	int height;


};
Node* Root;

int max(int a, int b);

int height(Node* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;

		node->left = NULL;
	node->right = NULL;
	node->height = 1;
	
	return(node);
}

Node* rightRotate(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left = T2;
	
	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;
	
	return x;
}

Node* leftRotate(Node* x)
{
	Node* y = x->right;
	Node* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;
	
	return y;
}

int getBalance(Node* N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}


Node * insert(Node * node, int key)
{
	
	if (node == NULL)
		return(newNode(key));
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else 
		return node;

	node->height = 1 + max(height(node->left),
		height(node->right));

	int balance = getBalance(node);
	
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}
void inorder(Node* tree)

{
	if (tree == NULL) {
		return;
	}
	inorder(tree->left);
	cout << tree->key << ",";
	inorder(tree->right);
}
int main()
{

	char choice;
	int num;
	bool flag = true;

	while (flag)
	{
		cout << endl << endl;
		cout << "1: Insert a Node" << endl;
		cout << "2: Display the AVL Tree Inorder" << endl;
		cout << "3: Exit from program" << endl << endl;

		cout << "Enter a choice" << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			cout << "Enter number to be added in Tree" << endl;
			cin >> num;
			Root = insert(Root, num);
			break;

		}
		case '2':
		{

			inorder(Root);
			break;


		}

		case '3':
		{

			flag = false;
			break;

		}
		}
	}
}