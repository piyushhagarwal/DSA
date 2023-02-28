#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
	int data;
	node *left;
	node *right;

	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

node *buildTree(node *root)
{
	cout << "Enter data" << endl;
	int data;
	cin >> data;

	root = new node(data);
	if (root->data == -1)
	{
		return NULL;
	}

	cout << "Enter data you want to enter to the left of " << data << endl;
	root->left = buildTree(root->left);
	cout << "Enter data you want to enter to the right of " << data << endl;
	root->right = buildTree(root->right);
	return root;
}

void LevelOrderDisplay(node *root)
{
	queue<node *> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		node *temp = q.front();
		q.pop();

		if (temp == NULL)
		{
			cout << endl;
			if (!q.empty())
			{
				q.push(NULL);
			}
		}

		else
		{
			cout << temp->data << " ";
			if (temp->left)
			{
				q.push(temp->left);
			}
			if (temp->right)
			{
				q.push(temp->right);
			}
		}
	}
}

void levelOrderInsertion(node *&root)
{

	cout << "Enter data of root node" << endl;
	int data;
	cin >> data;
	root = new node(data);
	queue<node *> q;
	q.push(root);

	while (!q.empty())
	{
		node *temp = q.front();
		q.pop();

		cout << "Enter data for left node of " << temp->data << endl;
		int leftData;
		cin >> leftData;
		if (leftData != -1)
		{
			temp->left = new node(leftData);
			q.push(temp->left);
		}

		cout << "Enter data for right node of " << temp->data << endl;
		int rightData;
		cin >> rightData;
		if (rightData != -1)
		{
			temp->right = new node(rightData);
			q.push(temp->right);
		}
	}
}

void inOrder(node *root)
{
	if (root == NULL)
	{
		return;
	}

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void preOrder(node *root)
{
	if (root == NULL)
	{
		return;
	}

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(node *root)
{
	if (root == NULL)
	{
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

void countLeafNodes(node *root, int &count)
{

	if (root == NULL)
	{
		return;
	}

	countLeafNodes(root->left, count);
	if (root->left == NULL && root->right == NULL)
	{
		count++;
	}
	countLeafNodes(root->right, count);
}

int main()
{
	node *root = NULL;
	root = buildTree(root);
	// levelOrderInsertion(root);
	LevelOrderDisplay(root);
	inOrder(root);
	cout << endl;
	preOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;
	int count = 0;
	countLeafNodes(root, count);
	cout << "The count of leaf nodes are " << count << endl;
}