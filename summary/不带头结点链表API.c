#pragma warning(disable:4996)
#include<stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LinkNode {
	ElemType data;
	struct LinkNode *next;
}LinkNode, *LinkList;
//�����ʼ��
void InitLinkedList(LinkList* list) {
	*list = (LinkNode*)malloc(sizeof(struct LinkNode));
	(*list)->next = NULL;
}
//���������λ�ò���
void Insert(LinkList *list, ElemType elem) {
	LinkList l = (*list);
	while (l->next != NULL) l = l->next;
	LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
	node->data = elem;
	node->next = NULL;
	l->next = node;
}
//�������ָ��λ�ò��룬i=1��ʾ�ڵ�һ��λ�ò����ֵ
InsertLinkListAtPos(LinkList *list, int i, ElemType elem) {
	LinkList l = *list;
	while (--i)  l = l->next;
	LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
	node->data = elem;
	node->next = NULL;
	node->next = l->next;
	l->next = node;
}

//ɾ���������λ�õ�Ԫ��
void DeleteLastElem(LinkList *list) {
	LinkList l = (*list);
	while (l->next->next->next != NULL) l = l->next;
	l->next->next = l->next->next->next;
}

//ɾ��ָ��λ��i������ֵ������elem����
DeleteLinkeListAtPos(LinkList *list, int i, ElemType* elem) {
	LinkList l = *list;
	while (--i) l = l->next;
	LinkList p = l->next;
	*elem = p->data;
	l->next = l->next->next;
	free(p);
}
//����Ĵ���
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
//��������
void Traversal(LinkList list){
	while (list->next)
	{
		printf("%d ", list->next->data);
		list = list->next;	
	}
}
//�����ӡ����
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