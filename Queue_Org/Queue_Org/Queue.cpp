#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct QueueNode {
	int item;
	struct QueueNode *link;
}QueueNode;

typedef struct {
	QueueNode *front, *rear;
}QueueType;

int is_empty(QueueType *q)
{
	return (q->front == NULL);
}

void init(QueueType *q)
{
	q->front = q->rear = NULL;
}

void enqueue(QueueType *q, int item)
{
	QueueNode *temp = new QueueNode();
	if (temp == NULL)
		fprintf(stderr, "Memory Allocation Failed\n");
	else
	{
		temp->item = item;
		temp->link = NULL;
		if (is_empty(q))
		{
			q->front = temp;
			q->rear = temp;
		}
		else
		{
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}

int dequeue(QueueType *q)
{
	QueueNode *temp = q->front;
	int item;
	if (is_empty(q))
	{
		fprintf(stderr, "Queue is Empty!\n");
	}
	else
	{
		item = temp->item;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return item;
	}
}

int peek(QueueType *q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "Queue is Empty!\n");
	}
	else
	{
		return q->front->item;
	}
}

int main()
{
	QueueType q; init(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	for (int i = 0; i < 3; i++)
		printf("%d\n", dequeue(&q));

}