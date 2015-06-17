#ifndef CODE202_TREE_H
#define CODE202_TREE_H

#include <iostream>
using namespace std;

struct TreeNode
{
	int	key
	int	data;
	TreeNode *left;
	TreeNode *right;
};

class Tree
{
    private:
        TreeNode *root;

    public:
        Tree();
        ~Tree();
        bool isEmpty();
        TreeNode *SearchTree(int Key);
        int Insert(TreeNode *newNode);
        int Insert(int data);
        int Delete(int Key);
        void PrintOne(TreeNode *T);
        void PrintTree();
    private:
        void ClearTree(TreeNode *T);
        TreeNode *DupNode(TreeNode * T);
        void PrintAll(TreeNode *T);
};

#endif
