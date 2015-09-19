#pragma warning(disable:4996)
#include<stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LinkNode {
	ElemType data;
	struct LinkNode *next;
}LinkNode, *LinkList;
//链表初始化
void InitLinkedList(LinkList* list) {
	*list = (LinkNode*)malloc(sizeof(struct LinkNode));
	(*list)->next = NULL;
}
//链表在最后位置插入
void Insert(LinkList *list, ElemType elem) {
	LinkList l = (*list);
	while (l->next != NULL) l = l->next;
	LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
	node->data = elem;
	node->next = NULL;
	l->next = node;
}
//在链表的指定位置插入，i=1表示在第一个位置插入该值
InsertLinkListAtPos(LinkList *list, int i, ElemType elem) {
	LinkList l = *list;
	while (--i)  l = l->next;
	LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
	node->data = elem;
	node->next = NULL;
	node->next = l->next;
	l->next = node;
}

//删除链表最后位置的元素
void DeleteLastElem(LinkList *list) {
	LinkList l = (*list);
	while (l->next->next->next != NULL) l = l->next;
	l->next->next = l->next->next->next;
}

//删除指定位置i的链表值，并用elem返回
DeleteLinkeListAtPos(LinkList *list, int i, ElemType* elem) {
	LinkList l = *list;
	while (--i) l = l->next;
	LinkList p = l->next;
	*elem = p->data;
	l->next = l->next->next;
	free(p);
}
//链表的创建
void CreateLinkList(LinkList *list) {
	int data;
	scanf("%d", &data);
	if (data != 0)
	{
		LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
		node->data = data;
		node->next = NULL;
		(*list)->next = node;
		CreateLinkList(&(*list)->next);
	}
}
//遍历链表
void Traversal(LinkList list){
	while (list->next)
	{
		printf("%d ", list->next->data);
		list = list->next;	
	}
}
//逆序打印链表
void InvertedLinkList(LinkList list) {
	if (list->next) {
		InvertedLinkList(list->next);
	}
	printf("%d\n",list->data);
}
int main() {
	LinkList list;
	//ElemType elem;
	InitLinkedList(&list);
	CreateLinkList(&list);
	DeleteLastElem(&list);

	//InsertLinkListAtPos(&list, 1, 3);
	//DeleteLinkeListAtPos(&list,2,&elem );
	//InvertedLinkList(list);
	//printf("%d", elem);
	Traversal(list);
	
	//Insert(&list, 5);
	//printf("%d\n",list->next->data);
	return 0;
}