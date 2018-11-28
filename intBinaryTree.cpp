/*
program name: intBinaryTree.cpp
programmer:	  Andrew Valle
Date:		  5-24-2018
*/

#include <iostream>
using namespace std;


class IntBinaryTree
{
	private:
		struct TreeNode
		{
			int value;      // The value in the node
			TreeNode *left; // Pointer to left child node
			TreeNode *right; // Pointer to right child node
		};

		TreeNode *root; // Pointer to the root node;

		// Private member functions
		void insert(TreeNode *& nodePtr, TreeNode*& newNode)
		{
			if (nodePtr == NULL) //It is at the end of branch and insertion point has been found
				nodePtr = newNode; // Insert data

			else if (newNode->value < nodePtr->value)
				insert(nodePtr->left, newNode); // Search Left

			else
				insert(nodePtr->right, newNode); // Search Right
		}
		void deleteNode(int num, TreeNode *& nodePtr)
		{
			if (num < nodePtr->value)
				deleteNode(num, nodePtr->left);
			else if (num > nodePtr->value)
				deleteNode(num, nodePtr->right);
			else
				makeDeletion(nodePtr);
		}
		void makeDeletion(TreeNode *& nodePtr)
		{
			//Define a temporary pointer to use in reattaching the left subtree
			TreeNode *tempNodePtr = nullptr;

			if (nodePtr == nullptr)
				cout << "Cannot delete empty node.\n";

			else if (nodePtr->right == nullptr)
			{
				tempNodePtr = nodePtr;
				nodePtr = nodePtr->left; //Reattach the left child
				delete tempNodePtr;
			}

			else if (nodePtr->left == nullptr)
			{
				tempNodePtr = nodePtr;
				nodePtr = nodePtr->right; //Reattach the right child
				delete tempNodePtr;
			}

			//If the node has two children
			else
			{
				//Move one node to the right.
				tempNodePtr = nodePtr->right;
				//Go to the end of left node.
				while (tempNodePtr->left)
					tempNodePtr = tempNodePtr->left;
				//Reattach the left subtree.
				tempNodePtr->left = nodePtr->left;
				tempNodePtr = nodePtr;
				//Reattach the right subtree.
				nodePtr = nodePtr->right;
				delete tempNodePtr;
			}

		}
		void displayInOrder(TreeNode *nodePtr) const
		{
			if (nodePtr)
			{
				displayInOrder(nodePtr->left);
				cout << nodePtr->value << endl;
				displayInOrder(nodePtr->right);
			}
		}
		void displayPreOrder(TreeNode *nodePtr) const
		{
			if (nodePtr)
			{
				cout << nodePtr->value << endl;
				displayPreOrder(nodePtr->left);
				displayPreOrder(nodePtr->right);
			}
		}
		void displayPostOrder(TreeNode *nodePtr) const
		{
			if (nodePtr)
			{
				displayPostOrder(nodePtr->left);
				displayPostOrder(nodePtr->right);
				cout << nodePtr->value << endl;
			}
		}

		//counts number of nodes in binary tree
		int numNodes(TreeNode *nodePtr)
		{
			if (nodePtr == NULL) 
				return 0;

			else
				return 1 + numNodes(nodePtr->left) + numNodes(nodePtr->right);
		}

		//counts number of leaf nodes in binary tree
		int numLeafNodes(TreeNode *nodePtr)
		{
			if (nodePtr == NULL)
				return 0;
			else if (nodePtr->left == NULL && nodePtr->right == NULL)
				return 1;
			else
				return (numLeafNodes(nodePtr->left) + numLeafNodes(nodePtr->right));
		}


	public:
		// Constructor
		IntBinaryTree()
		{
			root = nullptr;
		}


		// Binary tree operations
		void insertNode(int num)
		{
			TreeNode *newNode = nullptr;
			newNode = new TreeNode; //create a new node
			newNode->value = num;
			newNode->left = NULL;
			newNode->right = NULL;
			insert(root, newNode);
		}
		void remove(int num)
		{
			deleteNode(num, root);
		}
		void displayInOrder() const
		{
			displayInOrder(root);
		}
		void displayPreOrder() const
		{
			displayPreOrder(root);
		}
		void displayPostOrder() const
		{
			displayPostOrder(root);
		}

		int numNodes()
		{
			int n = numNodes(root);
			return n;
		}

		int numLeafNodes()
		{
			int n = numLeafNodes(root);
			return n;
		}
};



void menu(IntBinaryTree);



int main()
{
	IntBinaryTree tree;
	int choice;

	menu(tree);
	cin >> choice;

	while(choice>=1 && choice <=6)
	{
		switch(choice)
		{
			case 1:
			{
				int num, numNodes;
				
				cout << endl;
				cout << "How many nodes would you like to insert? ";
				cin >> numNodes;

				for (int i = 0; i < numNodes; i++)
				{
				cout << "Enter node #" << (i + 1) << ": ";
				cin >> num;
				tree.insertNode(num);
				}

				cout << endl;

			}
			break;

			case 2:
			{
				int num;
            	
            	cout << "Enter the number you want to delete: ";
            	cin >> num;
            	tree.remove(num);
            	cout << endl;
			} 
				break;

			case 3:
			{
				tree.displayPreOrder();
				cout << endl;
			}
				break;

			case 4:
			{
				tree.displayInOrder();
				cout << endl;
			}
				break;

			case 5:
			{
				tree.displayPostOrder();
				cout <<endl;
			}
				break;

			case 6:
			{
				cout << "There are " << tree.numNodes() << " nodes in this binary tree.\n";
				cout << "There are " << tree.numLeafNodes() << " leaf nodes in this binary tree.\n\n";
			}
				break;

			default:
				break;

		}

		menu(tree);
		cin >> choice;
		cout << endl;
	}
	
	
	return 0;
}


void menu(IntBinaryTree tree)
{
	cout << "1. Insert Nodes" << endl;
	cout << "2. Delete Nodes" << endl;
	cout << "3. Display Nodes Pre-Order" <<endl;
	cout << "4. Display Nodes In-Order" << endl;
	cout << "5. Display Nodes Post-Order" << endl;
	cout << "6. Count Number of Nodes and Leaf Nodes" << endl;
	cout << "Any other key to Quit" << endl;
	cout << "Enter Choice: "; 

}