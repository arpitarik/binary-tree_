#include<iostream>
using namespace std;
		
//create node
class Node{
	public:
	int data;
	Node*parent;
	Node*left;
	Node*right;
	//constructor
	Node(int value){
		data=value;
		parent=NULL;
		left=NULL;
		right=NULL;
	}
};


class BiST{
	public:
	Node*root;
	BiST(){root=NULL;}
	
//insert
	void insert(int value){
		insert2(root,value);
	}
	void insert2(Node*curr,int value){
		//no root
		if(curr==NULL){root=new Node(value);}
		//root exist but data is less then root
		else if(value<curr->data){
			//pass to next one or create and add
			if(curr->left==NULL){
				curr->left=new Node(value);
				curr->left->parent=curr;
			}
			//else pass
			else{insert2(curr->left,value);}
		}
		//root exist but data is more then root
		else{
			//same create or pass to next one
			if(curr->right==NULL){
				curr->right=new Node(value);
				curr->right->parent=curr;
			}
			else{insert2(curr->right,value);}
		}
	}
//Display
//inorder (left,root,right) 
	void Displayin(){displayin(root);cout<<endl;}
	void displayin(Node*curr){
		//if empty tree
		if(root==NULL){cout<<"there is nothing to print"<<endl;}
		else{
			//go left and left.........print
			//come back print........go right
			//.......print right
			if(curr==NULL)return;		
			else{
				//if below code didn't get try to wright
				displayin(curr->left);
				cout<<curr->data<<",";
				displayin(curr->right);		
			}
		}
	}
//count elments
	int count(){cout<<ct(root)<<endl;}
	int ct(Node*curr){
			int s=0;
			if(curr==NULL){return 0;}
			else{s=ct(curr->left)+1+ct(curr->right);}
		return s;
	}
//node search

	Node* Search(int value){
		search(root,value);
	}		
	Node* search(Node* curr,int value){
		if(value==curr->data or curr==NULL)return curr;
		else{
			if(value>curr->data){
				search(curr->right,value);	
			}
			else search(curr->left,value);
			}
	}
//min from given node
	Node* findmin(int value){
		fn(Search(value));	
	}
	Node* fn(Node*curr){
		if(curr->left==NULL){return curr;}
		else fn(curr->left);
	}	


	int rangeSearch(int k1,int k2){
		

		cout<<disnct(root,k1,k2,10)<<endl;
	}
	int disnct(Node*curr,int k1,int k2,int count){
		//if empty tree
		if(root==NULL){cout<<"tree is empty"<<endl;}
		else if(curr==NULL) return count;
		else {
			disnct(curr->left,k1,k2,count);
			if(k1<=curr->data and curr->data<=k2){
				count++;				
				cout<<curr->data<<",";			
			}
			disnct(curr->right,k1,k2,count);	
		}
		return count;
}		
// height of a tree
	int height(int value){
		int maxh=0;
		Node*curr=Search(value);
		cout<<ht(curr,maxh)<<endl;
	}
	int ht(Node * curr,int maxh){
		if(curr==NULL)return 0;
		else{
			
			if(ht(curr->left,maxh)<ht(curr->right,maxh))maxh=ht(curr->right,maxh)+1;
			else maxh=ht(curr->left,maxh)+1;
		}
	return maxh;
	}


};

int main(){
	BiST b1;
	b1.insert(40);
	b1.insert(20);
	b1.insert(60);
	b1.insert(10);
	b1.insert(30);
	b1.insert(50);	
	b1.insert(70);
	b1.insert(65);
	b1.insert(75);
	b1.insert(5);
	b1.insert(15);
	b1.insert(25);
	b1.insert(35);
	b1.insert(45);
	b1.insert(55);	
	b1.insert(1);
	b1.insert(54);
	b1.insert(53);
	b1.insert(52);
	b1.insert(51);
	b1.insert(65);
	b1.insert(32);
	b1.insert(33);
	b1.insert(68);
	b1.Displayin();
//b1.height(40);
//b1.count();
	b1.rangeSearch(50,60);

	return 0;
}
