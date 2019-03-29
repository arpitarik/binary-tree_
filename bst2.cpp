#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node * left;
    Node * right;
    Node * parent;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
        parent = NULL;
    }  
};

class BST{
public:
    Node * root;
    BST(){
        root = NULL;
    }
    void insertHelper(int val){
        insert(root, val);
    }
    void insert(Node *curr, int val){
        // If root is NULL, then create a node and make it root. 
        if (root == NULL) root = new Node(val);
        // Else Decide to move left or right. 
        else if (val < curr->data)  {
            // if left is already NULL, create a new node and link it. 
            if (curr->left == NULL) {
                curr->left = new Node(val);
                curr->left->parent = curr;
            }
            // Move left and call insert there. 
            else insert(curr->left, val);
        }
        else {
            // if right is already NULL, create a new node and link it. 
            if (curr->right == NULL) {
                curr->right = new Node(val);
                curr->right->parent = curr;
            }
            // Move right and call insert there. 
            else insert(curr->right, val);
        }
    }
    void displayHelper(){
        display(root);
    }
    void display(Node * curr){
        // Case for empty tree and leaf nodes children.
        if( curr ==  NULL) return;
        // IN order print.
        // Print left. 
        display(curr->left);
        // Print myself.
        cout << curr->data << ", ";
        // Print right.
        display(curr->right);
    }
    Node * searchHelper(int val){
        return search(root, val);
    }
    Node * search(Node * curr, int val){
        
        if(curr == NULL || curr->data == val ) return curr;
        // else you search in right or left. 
        // Left
        else if(val < curr->data) return search(curr->left, val);
        // Right
        else  return search(curr->right, val);
    }
    void print2DUtil(Node *root, int space)  
    {  
        // Base case  
        if (root == NULL)  
            return;  
        // Increase distance between levels  
        space += 5;  
        // Process right child first  
        print2DUtil(root->right, space);  
    
        // Print current node after space  
        // count  
        cout<<endl;  
        for (int i = 5; i < space; i++)  
            cout<<" ";  
        cout<<root->data<<"\n";  
    
        // Process left child  
        print2DUtil(root->left, space);  
    }  
  
    // Wrapper over print2DUtil()  
    void print2D()  
    {  
        cout << "******************************" << endl;
        // Pass initial space count as 0  
        print2DUtil(root, 0);  
        cout << "******************************" << endl;
        
    }

    

    void binary_delete(Node * curr, int key){
        
    }

};

int main(){
    
    BST bst1;
    bst1.insertHelper(4);
    bst1.insertHelper(2);
    bst1.insertHelper(3);
    bst1.insertHelper(1);
    bst1.insertHelper(6);
    bst1.insertHelper(5);
    bst1.insertHelper(7);
    bst1.insertHelper(8);
    bst1.displayHelper();
    if(bst1.searchHelper(3) != NULL){
        cout << endl << bst1.searchHelper(3)->data << endl;
    }
    bst1.print2D();
    bst1.binary_delete(bst1.root,5);
    bst1.print2D();
    bst1.binary_delete(bst1.root,6);
    bst1.print2D();
    cout << "Deleting 2" << endl;
    bst1.binary_delete(bst1.root,2);
    bst1.print2D();
    bst1.binary_delete(bst1.root,4);
    bst1.print2D();
    bst1.binary_delete(bst1.root,7);
    bst1.print2D();
    bst1.binary_delete(bst1.root,8);
    bst1.print2D();
    bst1.binary_delete(bst1.root,3);
    bst1.print2D();
    bst1.binary_delete(bst1.root,1);
    bst1.print2D();
    bst1.binary_delete(bst1.root,1);
    bst1.print2D();

}
