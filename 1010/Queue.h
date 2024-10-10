#pragma once
#include <Windows.h>
#include <stdio.h>
typedef struct Node
{
	LPSTR string;
	Node* link;

}Root;

typedef struct Terminal
{
	Node* enter;
	Node* exit;
};

Node* EnQueue(LPSTR _string, Node* Rear)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->string = _string;
	node->link = NULL;
	if (Rear != NULL)
	{
		Rear->link = node;
	}
	return node;
}
Node* DeQueue(Node* Front)
{
	if (Front == NULL)
	{
		printf("_emptyQueue");
		return Front;
	}
	Node* DeleteNode = Front;
	Front = Front->link;
	free(DeleteNode);
	return Front;
}