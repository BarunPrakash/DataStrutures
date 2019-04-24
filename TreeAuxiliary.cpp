/**************************************************

Designed by Barun
objective :To learn Non Linear Data structure 
problems;->
1.check identical or not
2.swape noe
3. print digonal
4.print leaf node 
Date: 19:App:2019


**********************************/


#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stdbool.h>
#include <bits/stdc++.h> 
#include <climits>
/*****************************************************/
using namespace std;

typedef struct Bnode
{
  int data;
  Bnode *left;
  Bnode *right;
}Bnode;

/*********************************************************/
Bnode* creatNode(int key);
void preOrder(Bnode *root);
bool isItSymetric(Bnode *rootA ,Bnode *rootB);
bool  isItSymetric(Bnode *root);
void convertMirrorimage(Bnode *root);
bool  isITIdentical(Bnode  *rootA, Bnode *rootB);
void printDiagonal(Bnode *node, int diagonal, auto &map);
void printLeafToRootpath(Bnode *root);
void printLeafToRootpath(Bnode *root,vector<int> &path);
void printPath(vector<int> const &path);
void FindMaxWidth(Bnode* root);
void FindMaxWidth(Bnode* root);
void invertBTree(Bnode*root);
void invertBinaryTreeUsingQueue(Bnode* root);
Bnode* insertBstNode(Bnode* root, int key);
bool isBST(Bnode* node, int minKey, int maxKey);

/***********************************************************/

Bnode* creatNode(int key)
{
    
    Bnode *temp = (Bnode*)malloc(sizeof(Bnode));
    temp->left  = NULL;
    temp->right = NULL;
    temp->data  = key;
    return(temp);
}
/*****************************************************************/
void preOrder(Bnode *root)
{
  if(root==NULL)
        return;
        printf("%d\t",root->data);
        
      preOrder(root->left);
      preOrder(root->right);
}

/**************************************************************/
bool isItSymetric(Bnode *root)
{
    
    if(root==NULL)
        return true;
        
        isItSymetric(root->left,root->right);

}
/*******************************************************/
// Find symetric
bool isItSymetric(Bnode *rootA ,Bnode *rootB)
{
    
    if(rootA ==NULL &&rootB ==NULL)
        return true;
        
        return((rootA!=NULL&& rootB!=NULL) && \
        isItSymetric(rootA->left,rootB->right)&&isItSymetric(rootA->right,rootB->left));
}
/************************************************************************/
// find mirror Image

void convertMirrorimage(Bnode *root)
{
    if(root==NULL)
        return;
      //  printf("%d\t",root->data);
        
      preOrder(root->left);
      preOrder(root->right);
      swap(root->left,root->right);
}
// check wather it is identical or not
/*********************************************************************/

bool  isITIdentical(Bnode  *rootA, Bnode *rootB)
{
	// if both trees are empty, return true
	if (rootA == NULL && rootB == NULL)
		return 1;


	return (rootA && rootB) && (rootA->data == rootB->data) &&
		 isITIdentical(rootA->left, rootB->left) &&
		 isITIdentical(rootA->right, rootB->right);
}
// print Diagonal
/****************************************************************/
void printDiagonal(Bnode *node, int diagonal, auto &map)
{
	
	if (node == NULL)
		return;
 

	map.insert(make_pair(diagonal, node->data));
 

	printDiagonal(node->left, diagonal + 1, map);
 
	printDiagonal(node->right, diagonal, map);
}
 /*****************************************************************************/
// This is used to print Function to print the diagonal elements of given binary tree
void printDiagonal(Bnode *root)
{
	// create an empty map to store diagonal element in every slope
	// we can also use map<int, vector<int>> instead of multimap<int, int>
	multimap<int, int> map;


	printDiagonal(root, 0, map);
 
	// traverse the map and print diagonal elements
   	int temp = 0;
	for (auto it = map.begin(); it != map.end(); it++)
	{
		if (temp != it->first)
		{
			cout << endl;
			temp = it->first;
		}
		cout << it->second << " ";
	}
}

/**************************************************************/
// print leaf node in the tree.
void printLeafToRootpath(Bnode *root)
{
	vector<int> path;

	 printLeafToRootpath(root,path);


}
/*****************************************************/
void printLeafToRootpath(Bnode *root,vector<int> &path)
{
	if(root==NULL)
		return;


	path.push_back(root->data);
	if(root->left==NULL&&root->right==NULL)
	{
		printPath(path);
	}
	printLeafToRootpath(root->left,path);
	printLeafToRootpath(root->right,path);
}
/****************************************************************/
void printPath(vector<int> const &path)
{
	for (int i = path.size() - 1; i > 0; i--)
		cout << path.at(i) << " -> ";

	cout << path.at(0) << endl;
}
/**************************************************/
void FindMaxWidth(Bnode* root)
{
	if (root == NULL)
		return;

	// create an empty queue and enqueue root node
	list<Bnode*> queue;
	queue.push_back(root);

	Bnode *curr = NULL;

	// stores maximum width
	int max = 0;

	// run till queue is not empty
	while (!queue.empty())
	{
		// calculate number of nodes in current level
		// This is equal to width of current level
	//	printf("%d",root->data);
		int width = queue.size();

		// update maximum width if number of nodes in current level
		// is more than maximum width found so far
		if (max < width)
			max = width;

		// process every node of current level and enqueue their
		// non-empty left and right child to queue
		while (width--)
		{
			curr = queue.front();
			printf("%d\t",curr->data);
	//		printf("\n");
			queue.pop_front();

			if (curr->left)
				queue.push_back(curr->left);

			if (curr->right)
				queue.push_back(curr->right);
		}
	}

	cout << "Maximum width is " << max;
}
/********************************************************************/
void invertBTree(Bnode*root)
{
	// base case: if tree is empty
	if (root == nullptr)
		return;
 
	// swap left subtree with right subtree
	swap(root->left, root->right);
 
	// invert left subtree
	invertBTree(root->left);
 
	// invert right subtree
	invertBTree(root->right);
}
/**************************************************************************************/
void invertBinaryTreeUsingQueue(Bnode* root) 
{
	// base case: if tree is empty
	if (root == nullptr) 
		return;
 
	// maintain a queue and push push root node
	queue<Bnode*> q;
	q.push(root);
 
	// run till queue is not empty
	while (!q.empty()) 
	{
		// pop top node from queue
		Bnode* curr = q.front();
		q.pop();
 
		// swap left child with right child
		swap(curr->left, curr->right);
 
		// push left child of popped node to the queue
		if (curr->left)
			q.push(curr->left);
 
		// push right child of popped node to the queue
		if (curr->right)
			q.push(curr->right);
	}
}
/**********************************************************************************/
Bnode* insertBstNode(Bnode* root, int key)
{

	if (root == nullptr)
		return creatNode(key);

	
	if (key < root->data)
		root->left = insertBstNode(root->left, key);


	else
		root->right = insertBstNode(root->right, key);

	return root;
}

/**************************************************************************/
bool isBST(Bnode* node, int minKey, int maxKey)
{
	// base case
	if (node == NULL)
		return true;

	// if node's value fall outside valid range
	if (node->data < minKey || node->data > maxKey)
		return false;

	// recursively check left and right subtrees with updated range
	return isBST(node->left, minKey, node->data) &&
			isBST(node->right, node->data, maxKey);
}
/**************************************************************************/
// Function to determine if given Binary Tree is a BST or not
void isBST(Bnode* root)
{
	if(isBST(root, INT_MIN, INT_MAX))
		printf("This is a BST.");
	else
		printf("This is NOT a BST!");
}
/**************************************************************************/
int main()
{
    Bnode *root=NULL;
   int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
   for (int key : keys)
		root = insertBstNode(root, key);

	// swap nodes
//	swap(root->left, root->right);
	isBST(root);

 /*   root        =creatNode(1);
    root->left  =creatNode(2);
    root->right =creatNode(3);
    root->left->left =creatNode(4);
    root->left->right=creatNode(6);
    root->right->right =creatNode(7);
    //preOrder(root);
    //isItSymetric(root);
    //convertMirrorimage(root);
    FindMaxWidth(root);

	
    printf("my:-%d\n", isItSymetric(root));*/

    return 0;
}
