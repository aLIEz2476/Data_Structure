// 본 기본코드의 분석을 우선으로 진행한다.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct StackNode {
	int item;
	struct StackNode *link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

void init(LinkedStackType *s)
{
	s->top = NULL;
}

int is_empty(LinkedStackType *s)
{
	return (s->top == NULL);
}

void push(LinkedStackType *s, int item)
{
	StackNode* temp = new StackNode();
	if (temp == NULL)
	{
		fprintf(stderr, "Memory Allocation Error!\n");
		return;
	}
	else
	{
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}

int pop(LinkedStackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "Stack is Empty\n");
		exit(1);
	}
	else
	{
		StackNode* temp = s->top;
		int item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}

int peek(LinkedStackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "Stack is Empty\n");
		exit(1);
	}
	else
	{
		return s->top->item;
	}
}


int main()
{
	
	LinkedStackType s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	for (int i = 0; i < 3; i++)
		printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));
}