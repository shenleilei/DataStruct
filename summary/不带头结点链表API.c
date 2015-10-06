//不带头节点的明显操作比较简单
#pragma warning(disable:4996)
#include<stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LinkNode {
	ElemType data;
	struct LinkNode *next;
}LinkNode, *LinkList;

//链表在最后位置插入
void Insert(LinkList *list, ElemType elem) {
	LinkList l = (*list);
	while (l->next!= NULL) l = l->next;
	l->next= (LinkNode*)malloc(sizeof(LinkNode));
	l->next->data = elem;
	l->next->next = NULL;
}

//删除链表最后位置的元素
void DeleteLastElem(LinkList *list) {
	LinkList l = (*list);
	while (l->next->next!= NULL) l = l->next;
	l->next=NULL;
}

//链表的创建
void CreateLinkList(LinkList *list) {
	int data;
	scanf("%d", &data);
	if (data != 0)
	{
		(*list) = (LinkNode*)malloc(sizeof(LinkNode));
		(*list)->data = data;
		(*list)->next = NULL;
		CreateLinkList(&(*list)->next);
	}
}
//遍历链表
void Traversal(LinkList list) {
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
}
//逆序打印链表
void InvertedLinkList(LinkList list) {
	if (list->next) {
		InvertedLinkList(list->next);
	}
	printf("%d  ", list->data);
}
int main() {
	LinkList list=NULL;
	CreateLinkList(&list);
	Insert(&list, 5);
	DeleteLastElem(&list);
	Traversal(list);
	return 0;
}