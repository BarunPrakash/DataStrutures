#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/************************************************************************************/



typedef struct Bnode
{
	int numb;
	struct Bnode *left;
	struct Bnode *right;
}Bnode;
/*************************************************************************************/

int findHeight(struct Bnode *temp);


/***********************************************************************************/

struct Bnode* creatnewNode(int val)
{

	struct Bnode *temp=(struct Bnode*)malloc(sizeof (struct Bnode));
	temp->numb=val;
	temp->left=NULL;
	temp->right=NULL;
	return (temp);
}
void printNode(struct Bnode *temp)
{
	if(!temp)
		return;
	printNode(temp->left);
	printNode(temp->right);
	printf("%d\n",temp->numb);
	
	
	
	

}
void deleteNode(struct Bnode *temp)
{
	if(!temp)
		return;
	deleteNode(temp->left);
	deleteNode(temp->right);
	free(temp);



}
/**************************************************************/
//searching node!!
void findElement(struct Bnode *temp,int ele)
{
	if(!temp)
		return;
	if(temp->numb==ele)
	{
		printf("found:---%d\n",temp->numb);
		return;
	}
	else if(temp->numb <ele)
	{
		findElement(temp->left,ele);

	}
	else if(temp->numb>ele)
	{
		findElement(temp->right,ele);
	}


}

/**********************************************************/

int findHeight(struct Bnode *temp)
{
	unsigned   int lefth,righth;
	if(!temp)
		return;
	lefth=findHeight(temp->left);
	righth=findHeight(temp->right);
	if(righth<lefth)
		return(righth+1);
	else
		return(lefth+1);
}
/**********************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/********************************************************************

Author: Barun Prakash

Purpose: This is ceated for learning purpose under public domain.

Date:    12 Aug 17 Revsion by 2 Sept

Contain : BST creation ,searching,Deleting( Basic operations!!!!!!!!!!!!)

reach Me : embeddedboss@gmail.com 

*********************************************************************/

/**************************************************************************
This file contains
Tree and tree trasversal 










*************************************************************************/



//define BST node
typedef struct BST
{
	int data;
	struct BST *left;
	struct BST *right;

}BST;

/*******************************************************************/
//creat Node
BST* creatNode(int key)
{
	
	BST *newNode=(BST*)malloc(sizeof(BST));
	newNode->left=NULL;
	newNode->right=NULL;
	newNode->data=key;
	return(newNode);

}
/********************************************************************/

//insert BST
BST* insertBST(BST *root ,int num)
{
	
	if(root==NULL)
		return creatNode(num);

	if(num<root->data)
		root->left=insertBST(root->left,num);
	if(num>root->data)
		root->right=insertBST(root->right,num);


	return(root);	
}

/************************************************************************/
// print preorder

void printInOrder(BST *node)
{
	if(!node)
		return;
	printInOrder(node->left);
	printf("%d\n",node->data);
	printInOrder(node->right);

}


/***********************************************************************/
// Stores inoder traversal of the BST 
// in arr[] i
void storeSorted(BST *root, int arr[],int *i)
{ 
    if (root != NULL) 
    { 
        storeSorted(root->left, arr, i); 
        arr[(*i)++] = root->data; 
        storeSorted(root->right, arr, i); 
    } 
} 
  
/**************************************************************************/
void treeSort(int arr[], int n) 
{ 

  
	BST *root=NULL;
  int i=0;  
    root = insertBST(root, arr[0]); 
    for (i=0; i<n; i++) 
        insertBST(root, arr[i]); 
  
    storeSorted(root, arr, &i); 
} 
/*******************************************************************************/
/*int main()
{
//	BST *root=NULL;
	int arr[6]= {10,20,7,50,70,15};
	int x=0;
//	root=insertBST(root,1);
//	insertBST(root,2);
	treeSort( arr, 6); 
	for(x=0; x<6;x++)
	printf("%d\n",arr[x]);
	insertBST(root,3);
	insertBST(root,4);
	insertBST(root,5);
	insertBST(root,6);
	insertBST(root,7);
	insertBST(root,8);
	insertBST(root,9);
	insertBST(root,10);
	insertBST(root,11);*/
	//printInOrder(root);
	return 0;
}*/

int main()
{

	struct Bnode *root=NULL;
	root=creatnewNode(1);
	root->left=creatnewNode(2);
	root->right=creatnewNode(3);
	printNode(root);
	findElement(root,2);
	printf("H---%d\n",findHeight(root));
	deleteNode(root);
	return 1;
	
}
