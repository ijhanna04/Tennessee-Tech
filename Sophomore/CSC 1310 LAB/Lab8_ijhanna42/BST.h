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

		void copy(treeNode*& newNode, treeNode* node){
			if (node == nullptr){
				newNode = nullptr;
			} else {
				newNode->value = node->value;
				copy(newNode->left, node->right);
				copy(newNode->right, node->right);
			}
		}

		void insert(treeNode*& node, treeNode* newNode){
			if (node == nullptr){
				node = newNode;
			} else if (newNode->value < node->value){
				insert(node->left, newNode);
			} else {
				insert(node->right, newNode);
			}
		}


		void displayInOrder(treeNode* node) const{
			if (node != nullptr){
				displayInOrder(node->left);
				cout << node->value << " ";
				displayInOrder(node->right);
			}
			
		}

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


		void insertNode(int value){
			treeNode* newNode = new treeNode(value);
			insert(root, newNode);
		}

		void display(){
			displayInOrder(root);
		}
};

#endif