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

class E : public std::exception {

	public:
		        explicit E(const char * s) throw() : msg(s) { }
			        const char * what() const throw() {return msg;}
	private:
				        E(){};
					        const char * msg;

};

template <typename T>
class TreeNode
{
	private:
		T data;
		TreeNode * left;
		TreeNode * right;

	public:
		TreeNode(){};
		TreeNode(const T & aData=0){data = aData; left = NULL; right = NULL;};

		T & GetData(){return data;};
		void SetData(const T & aData){data = aData;};

		void SetLeft(TreeNode * aNode){left = aNode;};
		void SetRight(TreeNode * aNode){right = aNode;};

		TreeNode* GetLeft(){return left;};
		TreeNode* GetRight(){return right;};

};

template <typename T>
class Tree
{

	private:
		TreeNode<T> *root;

	public:
		Tree();
		~Tree();
		bool isEmpty(){if(root == NULL) { return true;} return false;};

		int height();
		
		TreeNode<T> * Insert(const T & aData);
		TreeNode<T> * Search(const T & aData);
		TreeNode<T> * Delete(const T & aData);
		TreeNode<T> * MinValueNode(TreeNode<T> * node);
		TreeNode<T> * MaxValueNode(TreeNode<T> * node);
		int Size();
		//int Delete(int Key);
		void Print(int Traversal);
	private:
		void ClearTree(TreeNode<T> *Tr);
		//TreeNode *DupTreeNode(TreeNode<T> * T);

		int height_rec(TreeNode<T> * node);
		TreeNode<T> * Search_rec(TreeNode<T> * node, const T & aData);
		TreeNode<T> * Insert_rec(TreeNode<T> * node, const T & aData);
		TreeNode<T> * Delete_rec(TreeNode<T> * node, const T & aData);
		int Size_rec(TreeNode<T> * node);

		void Preorder(TreeNode<T> *root_member);
		void Inorder(TreeNode<T> *root_member);
		void Postorder(TreeNode<T> *root_member);
		void printLevelOrder(TreeNode<T> *root_member);

};

template <typename T>
Tree<T>::Tree()
{
	root = NULL;	
}

template <typename T>
Tree<T>::~Tree()
{
	ClearTree(root);
}

template <typename T>
void Tree<T>::ClearTree(TreeNode<T> *Tr)
{
	if(Tr==NULL) return;  // Nothing to clear
	if(Tr->GetLeft() != NULL) ClearTree(Tr->GetLeft()); // Clear left sub-tree
	if(Tr->GetRight() != NULL) ClearTree(Tr->GetRight()); // Clear right sub-tree
	delete Tr;    // Destroy this node
	return;
}

template <typename T>
int Tree<T>::height()
{
	if (root==NULL)
		return 0;
	else
	{
		return height_rec(root);
	}
}

template <typename T>
int Tree<T>::Size()
{
	if(root == NULL)
		return 0;
	else
	{
		return Size_rec(root);
	}

}

template <typename T>
int Tree<T>::Size_rec(TreeNode<T> * node)
{
	if (node == NULL)
	return 0;

	return Size_rec(node->GetLeft()) + 1 + Size_rec(node->GetRight());
}

template <typename T>
int Tree<T>::height_rec(TreeNode<T> * node)
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

template <typename T>
TreeNode<T> * Tree<T>::Search(const T & aData)
{
	if( (root == NULL) || (root->GetData() == aData) )
	{
		return root;
	} else {
		Search_rec(root, aData);
	}
	return root;
}

template <typename T>
TreeNode<T> * Tree<T>::Search_rec(TreeNode<T> * node, const T & aData)
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

template <typename T>
TreeNode<T> * Tree<T>::Insert(const T & aData)
{
	if(root == NULL)
	{
		root =  new TreeNode<T>(aData);
	} else {
		Insert_rec(root, aData);
	}

	return root;
}

template <typename T>
TreeNode<T> * Tree<T>::Insert_rec(TreeNode<T> * node, const T & aData)
{
	if(node == NULL)
		return ( new TreeNode<T>(aData) );

	if(aData > root->GetData())
	{
		node->SetRight( Insert_rec(node->GetRight(), aData) );
	} else {
		node->SetLeft( Insert_rec(node->GetLeft(), aData) ); 
	}
}

template <typename T>
TreeNode<T> * Tree<T>::MinValueNode(TreeNode<T> * node)
{
	while(node->GetLeft() != NULL){
		node = node->GetLeft();
	}
	return node;
}

template <typename T>
TreeNode<T> * Tree<T>::MaxValueNode(TreeNode<T> * node)
{
	while(node->GetRight() != NULL){
		node = node->GetRight();
	}
	return node;
}

template <typename T>
TreeNode<T> * Tree<T>::Delete(const T & aData)
{
        if(root == NULL)
        {
                return root;
        } else {
                Delete_rec(root, aData);
        }

        return root;
}

template <typename T>
TreeNode<T> * Tree<T>::Delete_rec(TreeNode<T> * node, const T & aData)
{
	if(node == NULL)
		return node;

	// If key is greater than root node, move towards right recursively.
	if(aData > node->GetData()){	// If key is greater than root node, move towards right recursively.
		node->SetRight(Delete_rec(node->GetRight(), aData));
	} else if (aData < node->GetData()) {	// If key is less than root node, move towards left recursively.
		node->SetLeft(Delete_rec(node->GetLeft(), aData));
	} else {	// If key is same as root node, this is the key to be deleted.

		if (node->GetLeft() == NULL){	// Recursion termination 1. Node with either no child or one child
			TreeNode<T> * temp = node->GetRight();
			delete node;
			return temp;
		} else if (node->GetRight() == NULL){	// Recursion termination 2. Node with either no child or one child
			TreeNode<T> * temp = node->GetLeft();
			delete node;
			return temp;

			// Recursion termination 3. Node with no child is also take care of in above to cases

		} else {	//	Node with two subtrees, replace it with it's "Inorder successor",
			//	which is in this case (2 sub-trees) is minimum value in Right subtree.
			TreeNode<T> * temp = MinValueNode(node->GetRight());	//	Find Inorder succesor
			node->SetData(temp->GetData());			//	Cope the data of inorder succesor
			node->SetRight( Delete_rec ( node->GetRight(), temp->GetData() ) );	//Recursively delete the inorder succesor
		}

		return node;	//	Keep returning the root of the tree formed after deletion of any given node
	}
}

template <typename T>
void Tree<T>::Print(int Traversal)
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

template <typename T>
void Tree<T>::Preorder(TreeNode<T> *root_member) {

	if(root_member == NULL)
		return;
	cout << root_member->GetData() << " ";
	Preorder(root_member->GetLeft());
	Preorder(root_member->GetRight());
}

template <typename T>
void Tree<T>::Inorder(TreeNode<T> *root_member) {

	if(root_member == NULL)
		return;
	Preorder(root_member->GetLeft());
	cout << root_member->GetData() << " ";
	Preorder(root_member->GetRight());
}

template <typename T>
void Tree<T>::Postorder(TreeNode<T> *root_member) {

	if(root_member == NULL)
		return;
	Preorder(root_member->GetLeft());
	Preorder(root_member->GetRight());
	cout << root_member->GetData() << " ";

}

template <typename T>
void Tree<T>::printLevelOrder(TreeNode<T> * root_member)
{

	if (root_member = NULL)  return;

	queue<TreeNode<T> *> q;

	q.push(root_member);

	while (1)
	{
		int nodeCount = q.size();
		if (nodeCount == 0)
			break;

		while (nodeCount > 0)
		{
			TreeNode<T> * node = q.front();
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


