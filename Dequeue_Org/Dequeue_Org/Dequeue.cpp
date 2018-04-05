#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DlistNode {
	int data;
	struct DlistNode *lLink;
	struct DlistNode *rLink;
} DlistNode;

typedef struct DequeType {
	DlistNode *head;
	DlistNode *tail;
} DequeType;

DlistNode *create_node(DlistNode *lLink, int item, DlistNode* rLink)
{
	DlistNode* node = new DlistNode();
	if (node == NULL) fprintf(stderr, "Memory Allocation Error");
	else
	{
		node->lLink = lLink;
		node->data = item;
		node->rLink = rLink;
		return node;
	}
}

void init(DequeType *dq)
{
	dq->head = dq->tail = NULL;
}

int is_empty(DequeType *dq)
{
	if (dq->head == NULL) return 1;
	else return 0;
}

void add_rear(DequeType *dq, int item)
{
	DlistNode *new_node = create_node(dq->tail, item, NULL);
	if (is_empty(dq)) dq->head = new_node;
	else dq->tail->rLink = new_node;
	dq->tail = new_node;
}

void add_front(DequeType *dq, int item)
{
	DlistNode *new_node = create_node(dq->head, item, NULL);
	if (is_empty(dq)) dq->tail = new_node;
	else dq->head->lLink = new_node;
	dq->head = new_node;
}

int delete_front(DequeType *dq)
{
	int item;
	DlistNode* removed_node;

	if (is_empty(dq)) fprintf(stderr, "Delete from NULL Dequeue");
	else
	{
		removed_node = dq->head;
		item = removed_node->data;
		dq->tail = dq->head->rLink;
		delete removed_node;
		if (dq->head == NULL)
			dq->tail == NULL;
		else dq->head->lLink = NULL;
	}
	return item;
}


int delete_rear(DequeType *dq)
{
	int item;
	DlistNode* removed_node;

	if (is_empty(dq)) fprintf(stderr, "Delete from NULL Dequeue");
	else
	{
		removed_node = dq->tail;
		item = removed_node->data;
		dq->tail = dq->tail->lLink;
		delete removed_node;
		if (dq->tail == NULL)
			dq->head == NULL;
		else dq->tail->rLink = NULL;
	}
	return item;
}

void display(DequeType *dq)
{
	DlistNode *p;
	printf("(");
	for (p = dq->head; p != NULL; p = p->rLink)
		printf("%d", p->data);
	printf(")\n");
}

int main()
{
	DequeType deque;
	init(&deque);

	add_front(&deque, 10); add_front(&deque, 20);
	add_rear(&deque, 30);
	display(&deque);

	delete_front(&deque); add_rear(&deque);
	display(&deque);
}