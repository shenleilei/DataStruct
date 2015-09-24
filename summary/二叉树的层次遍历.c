#include<stdlib.h>
#include<stdio.h>
typedef int Elem;
typedef struct BSTNode {
	Elem data;
	struct  BSTNode* lchild;
	struct  BSTNode* rchild;
}BSTNode, *BSTree;

typedef int ElemType;
typedef struct Qnode{
	BSTree elem;
	struct  Qnode* next;
}Qnode,*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr tail;
}LinkQueue;

InitQueue(LinkQueue *queue){
	(*queue).front = (*queue).tail = (Qnode*)malloc(sizeof(Qnode));
	(*queue).front ->next= NULL;
}

Enqueue(LinkQueue *queue, BSTree elem){
	Qnode *node = (Qnode*)malloc(sizeof(Qnode));
	node->elem = elem;
	node->next = NULL;
	(*queue).tail ->next= node;
	(*queue).tail=node;
}
Dequeue(LinkQueue *queue){
	(*queue).front->next=(*queue).front->next->next;
	if ((*queue).front->next == NULL){
		(*queue).tail = (*queue).front;
		//free();
	}
}
void Traversal(LinkQueue queue) {
	while (queue.front->next)
	{
		printf("%d ", queue.front->next->elem->data);
		queue.front = queue.front->next;
	}
}

BSTInsert(BSTree *tree, Elem elem) {
	if (*tree == NULL) {
		(*tree) = (BSTNode*)malloc(sizeof(BSTNode));
		(*tree)->data = elem;
		(*tree)->lchild = (*tree)->rchild = NULL;
		return 0;
	}
	if (elem < (*tree)->data) {
		BSTInsert(&((*tree)->lchild), elem);
	}
	else {
		BSTInsert(&((*tree)->rchild), elem);
	}
}
//Ê÷Èë¶ÓÁÐ
EnqueueTree(BSTree tree, LinkQueue* queue){
	BSTree p = NULL;
	if (tree)Enqueue(queue, tree);
	while ((*queue).front->next){
		p= (*queue).front->next->elem;
		Dequeue(queue);
		printf("%d ", p->data);
		if (p->lchild){
			Enqueue(queue, p->lchild);
		}
		if (p->rchild){
			Enqueue(queue, p->rchild);
		}
	}
}

int main(void){
	LinkQueue queue;
	InitQueue(&queue);

	BSTree tree = NULL;
	int a[9] = { 16, 8, 4, 3, 6, 10, 9, 46, 97 };
	for (int i = 0; i < 9; i++) {
		BSTInsert(&tree, a[i]);
	}                                                 
	EnqueueTree(tree,&queue);
	//Traversal(queue);
}