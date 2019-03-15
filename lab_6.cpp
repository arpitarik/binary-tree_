#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * left;
    Node * right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }  
};

class BST{
public:
    Node * root;
    BST(){
        root = NULL;
    }
    void insertHelper(int value){
        insert(root, value);
    }
    void insert(Node *curr, int value){
        // If root is NULL, create a node and make it root. 
        if (root == NULL) root = new Node(value);
        // Else move left or right. 
        else if (value < curr->data)  {
            // if left is NULL, create a new node and link it. 
            if (curr->left == NULL) curr->left = new Node(value);
            // Move left and insert there. 
            else insert(curr->left, value);
        }
        else {
            // if right is already null,create a new node and link it
            if (curr->right == NULL) curr->right = new Node(value);
	    // move right and call insert there
            else insert(curr->right, value);
        }
    }
    void displayHelper(){
        display(root);
    }
    void display(Node * curr){
        if( curr ==  NULL) return;
        // Print left. 
        display(curr->left);
        // Print self.
        cout << curr->data << ", ";
        // Print right.
        display(curr->right);
    }
    Node * searchHelper(int value){
        return search(root, value);
    }
    Node * search(Node * curr, int value){
        // Check the value
        if(curr == NULL || curr->data == value ) return curr;
        // else search in right or left. 
        // Left
        else if(value < curr->data) return search(curr->left, value);
        // Right
        else  return search(curr->right, value);
    }

};

int main(){
    BST bst1;
    bst1.insertHelper(4);
    bst1.insertHelper(2);
    bst1.insertHelper(1);
    bst1.insertHelper(3);
    bst1.insertHelper(5);
    bst1.displayHelper();
    if(bst1.searchHelper(3) != NULL)
	{
    		cout << endl << bst1.searchHelper(3)->data << endl;
    	}
}
