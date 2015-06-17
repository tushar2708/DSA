/*
 * linked_list.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: tdwivedi
 */



#include <iostream>
#include <queue>
using namespace std;

#define PRE_ORDER 1
#define IN_ORDER 2
#define POST_ORDER 3
#define LEVEL_ORDER 4
class TreeNode
{
	private:
		int data;
		TreeNode * left;
		TreeNode * right;

	public:
		TreeNode(){};
		TreeNode(int aData){data = aData; left = NULL; right = NULL;};

		int GetData(){return data;};
		void SetData(int aData){data = aData;};

		void SetLeft(TreeNode * aNode){left = aNode;};
		void SetRight(TreeNode * aNode){right = aNode;};

		TreeNode* GetLeft(){return left;};
		TreeNode* GetRight(){return right;};

};


class Tree
{

	private:
		TreeNode *root;

	public:
		Tree();
		~Tree();
		bool isEmpty(){if(root == NULL) { return true;} return false;};

		int height();
		TreeNode * Insert(int aData);
		TreeNode * Search(int aData);

		//int Delete(int Key);
		void Print(int Traversal);
	private:
		void ClearTree(TreeNode *T);
		//TreeNode *DupTreeNode(TreeNode * T);

		int height_rec(TreeNode * node);
		TreeNode * Search_rec(TreeNode * node, int aData);
		TreeNode * Insert_rec(TreeNode * node, int aData);

		void Preorder(TreeNode *root_member);
		void Inorder(TreeNode *root_member);
		void Postorder(TreeNode *root_member);
		void printLevelOrder(TreeNode *root_member);

};

Tree::Tree()
{

	root = NULL;	

}

Tree::~Tree()
{

	ClearTree(root);

}

void Tree::ClearTree(TreeNode *T)
{
	if(T==NULL) return;  // Nothing to clear
	if(T->GetLeft() != NULL) ClearTree(T->GetLeft()); // Clear left sub-tree
	if(T->GetRight() != NULL) ClearTree(T->GetRight()); // Clear right sub-tree
	delete T;    // Destroy this node
	return;
}

int Tree::height()
{

	if (root==NULL)
		return 0;
	else
	{
		return height_rec(root);
	}


}

int Tree::height_rec(TreeNode * node)
{
	if (node==NULL) 
		return 0;
	else
	{
		/* compute the depth of each subtree */
		int lDepth = height_rec(node->GetLeft());
		int rDepth = height_rec(node->GetRight());

		/* use the larger one */
		if (lDepth > rDepth) 
			return(lDepth+1);
		else
			return(rDepth+1);
	}
}

TreeNode * Tree::Search(int aData)
{

	if( (root == NULL) || (root->GetData() == aData) )
	{
		return root;
	} else {
		Search_rec(root, aData);
	}

	return root;
}

TreeNode * Tree::Search_rec(TreeNode * node, int aData)
{

	if( (node == NULL) || (node->GetData() == aData) ) 
		return root;

	if( aData > node->GetData() )
	{
		return Search_rec(node->GetRight(), aData);
	} else {
		return Search_rec(node->GetLeft(), aData);
	}

}

TreeNode * Tree::Insert(int aData)
{
	if(root == NULL)
	{
		root =  new TreeNode(aData);
	} else {
		Insert_rec(root, aData);
	}

	return root;
}

TreeNode * Tree::Insert_rec(TreeNode * node, int aData)
{

	if(node == NULL)
		return ( new TreeNode(aData) );

	if(aData > root->GetData())
	{
		node->SetRight( Insert_rec(node->GetRight(), aData) );
	} else {
		node->SetLeft( Insert_rec(node->GetLeft(), aData) ); 
	}

}

void Tree::Print(int Traversal)
{

	switch(Traversal)
	{
		case(PRE_ORDER):
			Preorder(root);
			cout << "\n";
			break;

		case(IN_ORDER):
			Inorder(root);
			cout << "\n";
			break;

		case(POST_ORDER):
			Postorder(root);
			cout << "\n";
			break;

		case(LEVEL_ORDER):
			printLevelOrder(root);
			cout << "\n";
			break;
		default :
			cout << "Invalid Traversal Value specified : " << Traversal << "\n";
	}
}

void Tree::Preorder(TreeNode *root_member) {

	if(root_member == NULL)
		return;
	cout << root_member->GetData() << " ";
	Preorder(root_member->GetLeft());
	Preorder(root_member->GetRight());
}

void Tree::Inorder(TreeNode *root_member) {

	if(root_member == NULL)
		return;
	Preorder(root_member->GetLeft());
	cout << root_member->GetData() << " ";
	Preorder(root_member->GetRight());
}

void Tree::Postorder(TreeNode *root_member) {

	if(root_member == NULL)
		return;
	Preorder(root_member->GetLeft());
	Preorder(root_member->GetRight());
	cout << root_member->GetData() << " ";

}

void Tree::printLevelOrder(TreeNode * root_member)
{

	if (root_member = NULL)  return;

	queue<TreeNode *> q;

	q.push(root_member);

	while (1)
	{
		int nodeCount = q.size();
		if (nodeCount == 0)
			break;

		while (nodeCount > 0)
		{
			TreeNode * node = q.front();
			if(node == NULL){
				q.pop();
				continue;
			}
			cout << node->GetData() << " ";
			q.pop();
			if (node->GetLeft() != NULL)
				q.push(node->GetLeft());
			if (node->GetRight() != NULL)
				q.push(node->GetRight());

			nodeCount--;	
		}
		cout << endl;
	}

}


