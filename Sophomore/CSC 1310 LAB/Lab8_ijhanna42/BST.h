#ifndef BST_H
#define BST_H

#include<iostream>
using namespace std;

class BST
{
	private:
		struct treeNode
		{
			int value;
			treeNode* left;
			treeNode* right;
		};
		treeNode* root;

		void copy(treeNode*&, treeNode*);
		void insert(treeNode*&, treeNode*);
		void displayInOrder(treeNode*) const;
		void destroySubTree(treeNode*);

	public:
		BST()			//default constructor
		BST(const BST &tree)	//copy constructor
		~BST()

		void insertNode(int);
		void display()
};

#endif