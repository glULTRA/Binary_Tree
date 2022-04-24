#include <iostream>

namespace BinaryTree
{
	struct Node{
		int data;
		Node* right;
		Node* left;
	};

	Node* GetNewNode(int data){
		Node* new_node = new Node();
		new_node->data = data;
		return new_node;
	}

	Node* Insert(Node* root, int data){
		if(root == NULL){
			// Get New Node.
			root = GetNewNode(data);
			return root;
		}
		else if(root->data >= data){
			// Ading data to left side.
			root->left = Insert(root->left, data);
		}else{
			root->right = Insert(root->right, data);
		}
	}

	Node* GetNodeByData(Node* root, int data){
		if(root == NULL) return root;

		if(root->data == data){
			return root;
		}else if(root->data >= data){
			return GetNodeByData(root->left, data);
		}else{
			return GetNodeByData(root->right, data);
		}
	}
	//Function to find minimum in a tree. 
	Node* FindMin(Node* root)
	{
		while(root->right != NULL) root = root->right;
		return root;
	}

	Node* Delete(Node* root, int data)
	{
		
		if(root == NULL)return root;
		else if(data < root->data) root->left = Delete(root->left, data);
		else if(data > root->data) root->right = Delete(root->right, data);
		else{
			// Case 1: No Child
			if(root->left == NULL && root->right == NULL){
				delete root;
				root = NULL;
			}
			// Case 2: One Child
			else if(root->left == NULL){
				Node* temp = root;
				root = root->right;
				delete temp;
			}
			else if(root->right == NULL){
				Node* temp = root;
				root = root->left;
				delete temp;
			}

			// Case 3: 2 Children
			else {
				Node* temp = FindMin(root->right);
				root->data = temp->data;
				root->right = Delete(root->right, temp->data);
			}

		}
		
		return root;
	}

	Node* Update(Node* root, int data, int new_data){
		Node* child = GetNodeByData(root, data);
		if(child != NULL)
		child->data = new_data;
		return root;
	}

	
};

using namespace std;
using namespace BinaryTree;

int main(){
	BinaryTree::Node* root = NULL;
	root = Insert(root, 150);
	root = Insert(root, 190);
	root = Insert(root, 110);
	root = Insert(root, 160);
	root = Insert(root, 200);
	root = Insert(root, 120);
	root = Insert(root, 130);
	root = Insert(root, 90);

	//root = Update(root, 90, 91);
	//root = Delete(root, 110);

	cout << "\t\t" <<  root->data << endl; 
	cout << "\t    " << root->left->data << "\t\t" << root->right->data << endl;
	cout << "\t" << root->left->left->data  << "   " << root->left->right->data;
	cout << "     " << root->right->left->data /*"oo"(*/ << "   " << root->right->right->data << "\t\t\n";
	//cout << "\t      " << root->left->right->right->data;

}
