// C++ program for different tree traversals
#include "../stdafx.h"
#include <queue>
#include <deque>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
		int data;
		struct node* left;
		struct node* right;
};

struct nodeLevel
{
		int level;
		struct node* treeNode;
};


// Utility function to create a new tree node
node* newNode(int data)
{
		node *temp = new node;
		temp->data = data;
		temp->left = temp->right = NULL;
		return temp;
}

// Utility function to create a new tree node
nodeLevel* newNodeLevel(node * treenode, int level)
{
		nodeLevel *temp = new nodeLevel;
		temp->treeNode = treenode;
		temp->level = level;
		return temp;
}

/* Function protoypes */
void printGivenLevel(struct node* root, int level);
int height(struct node* node);

/* Function to print level order traversal a tree*/
void printLevelOrder(struct node* root)
{
		int h = height(root);
		int i;
		for (i=1; i<=h; i++)
				printGivenLevel(root, i);
}

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
		if (root == NULL)
				return;
		if (level == 1)
				printf("%d ", root->data);
		else if (level > 1)
		{
				printGivenLevel(root->left, level-1);
				printGivenLevel(root->right, level-1);
		}
}

// Iterative method to find height of Bianry Tree
void printLevelOrderQ(node *root)
{
		// Base Case
		if (root == NULL)  return;

		// Create an empty queue for level order tarversal
		queue<node *> q;

		// Enqueue Root and initialize height
		q.push(root);

		while (q.empty() == false)
		{
				// Print front of queue and remove it from queue
				node *node = q.front();
				cout << node->data << " ";
				q.pop();

				/* Enqueue left child */
				if (node->left != NULL)
						q.push(node->left);

				/*Enqueue right child */
				if (node->right != NULL)
						q.push(node->right);
		}
}



// Iterative method to find height of Bianry Tree
void printLevelOrderAlternateQ(node *root)
{
		// Base Case
		if (root == NULL)  return;

		// Create an empty queue for level order tarversal
		deque<nodeLevel *> q1;
		deque<nodeLevel *> q2;

		// Enqueue Root and initialize height
		q1.push_front(newNodeLevel(root, 0));

		while (q1.empty() == false || q2.empty() == false )
		{
				// Print front of queue and remove it from queue

				while ( q1.empty() == false)
				{
						nodeLevel * temp = q1.front();
						cout << temp->treeNode->data << "(" << temp->level << ") ";
						q1.pop_front();

						/*Enqueue right child */
						if (temp->treeNode->right != NULL)
								q2.push_back(newNodeLevel(temp->treeNode->right, temp->level + 1));

						/* Enqueue left child */
						if (temp->treeNode->left != NULL)
								q2.push_back(newNodeLevel(temp->treeNode->left, temp->level + 1));
				}

				while ( q2.empty() == false)
				{
						nodeLevel * temp = q2.back();
						cout << temp->treeNode->data << "(" << temp->level << ") ";
						q2.pop_back();
						/* Enqueue left child */
						if (temp->treeNode->left != NULL)
								q1.push_front(newNodeLevel(temp->treeNode->left, temp->level + 1));

						/*Enqueue right child */
						if (temp->treeNode->right != NULL)
								q1.push_front(newNodeLevel(temp->treeNode->right, temp->level + 1));
				}

		}
}

/* Compute the "height" of a tree -- the number of
   nodes along the longest path from the root node
   down to the farthest leaf node.*/
int height(struct node* node)
{
		if (node==NULL)
				return 0;
		else
		{
				/* compute the height of each subtree */
				int lheight = height(node->left);
				int rheight = height(node->right);

				/* use the larger one */
				if (lheight > rheight)
						return(lheight+1);
				else return(rheight+1);
		}
}



/* Given a binary tree, print its nodes according to the
   "bottom-up" postorder traversal. */
void printPostorder(struct node* node)
{
		if (node == NULL)
				return;

		// first recur on left subtree
		printPostorder(node->left);

		// then recur on right subtree
		printPostorder(node->right);

		// now deal with the node
		printf("%d ", node->data);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
		if (node == NULL)
				return;

		/* first recur on left child */
		printInorder(node->left);

		/* then print the data of node */
		printf("%d ", node->data);  

		/* now recur on right child */
		printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
		if (node == NULL)
				return;

		/* first print data of node */
		printf("%d ", node->data);  

		/* then recur on left sutree */
		printPreorder(node->left);  

		/* now recur on right subtree */
		printPreorder(node->right);
}    

bool isPathWithSum(struct node * node, int sum){
	
	if(node == NULL)	// Leaf node
	{
		if(sum == 0)
		{
			cout << "true ";
			return true;
		} else {
			return false;
		}
	} else {

		cout << "node : " << node->data << "\t|\tsum before subtraction : " << sum << endl;
		return( isPathWithSum(node->left, (sum - node->data)) || isPathWithSum(node->right, (sum - node->data)) );
	}

}

void travrseAndFill(node * node, int * array, int column)
{
	if(node == NULL) return;
	array[column] += node->data;
	travrseAndFill(node->left, array, column - 1);
	travrseAndFill(node->right, array, column + 1);
}

void printVerticalSumArray(node * root)
{

		node *temp = root;
		int width = 0;

		while(temp != NULL){
				temp = temp->left;
				width++;
		}

		temp = root;
		width--;
		int mid = width;
		while(temp != NULL){
				temp = temp->right;
				width++;
		}

		int * array = new int[width];

		for (int i=0; i<width; i++)
			array[i] = 0;

		travrseAndFill(root, array, mid);
		for (int i=0; i<width; i++)
			cout << array[i] << " ";
}

/* Driver program to test above functions*/
int main()
{
		struct node *root			= newNode(1);

		root->left					= newNode(2);
		root->right					= newNode(3);

		root->left->left			= newNode(4);
		root->left->right			= newNode(5);
		root->right->left			= newNode(6);
		root->right->right			= newNode(7);

/*
		root->left->left->left		= newNode(8);
		root->left->left->right		= newNode(9);
		root->left->right->left		= newNode(10);
		root->left->right->right	= newNode(11);
        root->right->left->left		= newNode(12);
		root->right->left->right	= newNode(13);
		root->right->right->left	= newNode(14);
		root->right->right->right	= newNode(15);
*/
		std::cout << "\nPreorder traversal of binary tree is \n";
		printPreorder(root);

		std::cout << "\nInorder traversal of binary tree is \n";
		printInorder(root);  

		std::cout << "\nPostorder traversal of binary tree is \n";
		printPostorder(root);

		std::cout << "\nLevel Order traversal of binary tree is \n";
		printLevelOrderQ(root);

		std::cout << "\nLevel Order Alternate traversal of binary tree is \n";
		printLevelOrderAlternateQ(root);

		std::cout << "\nDoes the tree have a path with sum 15 ?\n";
		cout << ( (isPathWithSum(root, 15)) ? "true" : "false");
		cout << endl;

		std::cout << "\nVertical Sum array\n";
		printVerticalSumArray(root);
		return 0;
}
