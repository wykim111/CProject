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
    stNode* newNode = malloc(sizeof(stNode));
    
    if(head->next == NULL)
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

    while(cur != NULL)
    {
        printf("%d\n",cur->data);
        cur = cur->next;

    }

}

int removeNode(int rmData)
{
    stNode* delNode = head->next;
    stNode* preNode = head;

    if(delNode == NULL)
    {
        printf("unValid Node\n");
        return -1;
    }

    while(delNode != NULL)
    {
        if(delNode-> data == rmData)
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


int main()
{
   int cnt;
   int num;

   head = (stNode*)malloc(sizeof(stNode));

   scanf("%d",&cnt);

    for(int i=0;i<cnt;i++)
    {
        scanf("%d",&num);

        addNode(num);
    }


    iterList();
    
    //제거할 데이터
    removeNode(4);

    iterList();

    return 0;
}
