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

		// copy function
		void copy(treeNode*& newNode, treeNode* node){
			if (node == nullptr){
				newNode = nullptr;
			} else {
				newNode->value = node->value;
				copy(newNode->left, node->right);
				copy(newNode->right, node->right);
			}
		}

		// insert function
		void insert(treeNode*& node, treeNode* newNode){
			if (node == nullptr){
				node = newNode;
			} else if (newNode->value < node->value){
				insert(node->left, newNode);
			} else {
				insert(node->right, newNode);
			}
		}

		// displayInOrder function
		void displayInOrder(treeNode* node) const{
			if (node != nullptr){
				displayInOrder(node->left);
				cout << node->value << " ";
				displayInOrder(node->right);
			}
			
		}

		// destroySubTree function
		void destroySubTree(treeNode* node){
			if (node != nullptr){
				destroySubTree(node->left);
				destroySubTree(node->right);
				delete node;
			}
		}

	public:
		BST(){			//default constructor
			root = nullptr;
		}
		BST(const BST &tree){	//copy constructor
			copy(root, tree.root);
		}
		~BST(){
			destroySubTree(root);
		}

		// insertNode function
		void insertNode(int value){
			treeNode* newNode = new treeNode;
			newNode->value = value;
			insert(root, newNode);
		}

		// display function
		void display(){
			displayInOrder(root);
		}
};

#endif