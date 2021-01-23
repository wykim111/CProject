#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{

	int data;
	struct _node* next;

}stNode;


stNode* head;
stNode* tail;

void addNode(int num)
{
	stNode* newNode =(stNode*)malloc(sizeof(stNode));

	if (head->next == NULL)
	{
		newNode->data = num;
		newNode->next = NULL;

		head->next = newNode;
		tail = newNode;
	}
	else
	{
		newNode->data = num;
		newNode->next = NULL;

		tail->next = newNode;
		tail = newNode;

	}

}

void iterList()
{
	stNode* cur = head->next;

	if (cur == NULL)
	{
		printf("no valid\n");
		return;
	}

	while (cur != NULL)
	{
		printf("%d\n", cur->data);
		cur = cur->next;

	}

}

int removeNode(int rmData)
{
	stNode* delNode = head->next;
	stNode* preNode = head;

	if (delNode == NULL)
	{
		printf("unValid Node\n");
		return -1;
	}

	while (delNode != NULL)
	{
		if (delNode->data == rmData)
		{
			printf("success remove Data\n");

			preNode->next = delNode->next;
			free(delNode);
			return 1;

		}
		preNode = delNode;
		delNode = delNode->next;
	}

	return 0;
}

int searchNode(int target)
{
	stNode* curNode = head->next;

	if (curNode == NULL)
	{
		printf("No Target %d\n", target);
		return -1;
	}

	while (curNode != NULL)
	{
		if (curNode->data == target)
		{
			printf("success target :%d\n", target);
			return 1;

		}

		curNode = curNode->next;

	}

	printf("fail target:%d\n", target);


	return 0;
}


void deleteMem(stNode* delNode)
{
	stNode* curNode = delNode;

	if (delNode == NULL)
	{
		printf("empty Node\n");

		return;
	}


	while (curNode != NULL)
	{
		delNode = curNode;
		curNode = curNode->next;
		free(delNode);
	}

}

int main()
{
	int cnt;
	int num;

	head = (stNode*)malloc(sizeof(stNode));

	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++)
	{
		scanf("%d", &num);

		addNode(num);
	}


	iterList();

	//제거할 데이터
	removeNode(4);

	searchNode(9);

	iterList();


	deleteMem(head);

	return 0;
}
