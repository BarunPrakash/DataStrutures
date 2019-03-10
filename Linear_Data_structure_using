/*
	This is designed to pratice the linked list problems
	Designed by Barun prakash
	Date 3 march 2019




*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
/************************************************/
//structure
typedef struct linkedList
{
        int iNumb;
        struct linkedList *next;
}linkedList;


/****************************************************/
//function definition
void CreateStack(linkedList **node ,int data);
void printNode(linkedList *node);
void popStack(linkedList **node);
linkedList* createNode(int data);
void textSegmentForQueue(void);
void createQueue(linkedList **node,int data);
/**********************************************************/
// stack operation
void CreateStack(linkedList **node ,int data)
{
	linkedList *tempNode =NULL;
	tempNode = (linkedList*)malloc(sizeof(linkedList));
	tempNode->iNumb =data;
	tempNode->next =*node;
	*node =tempNode;

};

void popStack(linkedList **node)
{
	linkedList *tempNode =NULL;
	tempNode = *node;
	*node = tempNode->next;
	free(tempNode);


}
/************************************************************************/

//queue
linkedList* createNode(int data)
{
       linkedList *tempNode =NULL;
        tempNode = (linkedList*)malloc(sizeof(linkedList));
        tempNode->iNumb =data;
	tempNode->next =NULL;
	return(tempNode);


}
void createQueue(linkedList **node,int data)
{
	linkedList *tempNode =NULL;
	tempNode = *node;
	if(node==NULL)
	{
		tempNode =createNode(data);

	}
	else
	{
		for(;tempNode->next!=NULL;tempNode=tempNode->next);
		// nothing
		tempNode->next=createNode(data);
		
		
	}
	return;
}


void textSegmentForQueue(void)
{
	linkedList *tempNode =NULL;
	createQueue(&tempNode ,1);
        createQueue(&tempNode ,2);
	createQueue(&tempNode ,3);
	createQueue(&tempNode,4);
	printNode(tempNode);


}







/*****************************************************************************/
void printNode(linkedList *node)
{
	while(node->next!=NULL)
	{
		printf("%d\n",node->iNumb);
		node=node->next;
	}

		printf("\n");

}

int main()
{

 textSegmentForQueue();
/*	linkedList *refNode=NULL;
	CreateStack(&refNode ,1);
	CreateStack(&refNode ,2);
	 CreateStack(&refNode ,3);
	CreateStack(&refNode ,4);
	 CreateStack(&refNode ,5);
	printf("Hi!!\n");
	printNode(refNode);
	popStack(&refNode);
	printNode(refNode);*/
	return 0;

}
