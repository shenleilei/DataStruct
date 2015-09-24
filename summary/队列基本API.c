#include<stdlib.h>
#include<stdio.h>
typedef int ElemType;
typedef struct Qnode {
	ElemType elem;
	struct  Qnode* next;
}Qnode, *QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr tail;
}LinkQueue;
InitQueue(LinkQueue *queue) {
	(*queue).front = (*queue).tail = (Qnode*)malloc(sizeof(Qnode));
	(*queue).front->next = NULL;
}
Enqueue(LinkQueue *queue, ElemType elem) {
	Qnode *node = (Qnode*)malloc(sizeof(Qnode));
	node->elem = elem;
	node->next = NULL;
	(*queue).tail->next = node;
	(*queue).tail = node;
}
Dequeue(LinkQueue *queue) {
	(*queue).front->next = (*queue).front->next->next;
	if ((*queue).front->next == NULL) {
		(*queue).tail = (*queue).tail;
		//free();
	}
}
void Traversal(LinkQueue queue) {
	while (queue.front->next)
	{
		printf("%d ", queue.front->next->elem);
		queue.front = queue.front->next;
	}
}

int main(void) {
	LinkQueue queue;
	InitQueue(&queue);
	Enqueue(&queue, 5);
	Dequeue(&queue);
	Traversal(queue);
}