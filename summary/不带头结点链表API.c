//����ͷ�ڵ�����Բ����Ƚϼ�
#pragma warning(disable:4996)
#include<stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LinkNode {
	ElemType data;
	struct LinkNode *next;
}LinkNode, *LinkList;

//���������λ�ò���
void Insert(LinkList *list, ElemType elem) {
	LinkList l = (*list);
	while (l->next!= NULL) l = l->next;
	l->next= (LinkNode*)malloc(sizeof(LinkNode));
	l->next->data = elem;
	l->next->next = NULL;
}

//ɾ���������λ�õ�Ԫ��
void DeleteLastElem(LinkList *list) {
	LinkList l = (*list);
	while (l->next->next!= NULL) l = l->next;
	l->next=NULL;
}

//����Ĵ���
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
//��������
void Traversal(LinkList list) {
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
}
//�����ӡ����
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