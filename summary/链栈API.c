//#pragma warning(disable:4996)
//#include<stdio.h>
//#include<stdlib.h>
//typedef int ElemType;
//typedef struct stacknode {
//	ElemType elem;
//	struct stacknode* next;
//}stacknode, *stack;
////��ʼ��
//void InitLinkStack(stack *stack) {
//	*stack = (stacknode*)malloc(sizeof(stacknode));
//	stacknode* node = (stacknode*)malloc(sizeof(stacknode));
//	node = NULL;
//	(*stack)->next = node;
//}
////��ջ
//void CreateLinkStack(stack *stack) {
//	ElemType data;
//	scanf("%d", &data);
//	if (data)
//	{
//		stacknode* node = (stacknode*)malloc(sizeof(stacknode));
//		node->elem = data;
//		node->next = (*stack)->next;
//		(*stack)->next = node;
//		CreateLinkStack(&((*stack)->next));
//	}
//}
////ջ�ı���
//void TraversalLinkStack(stack stack) {
//	while (stack->next != NULL) {
//		printf("%d   ", (stack->next->elem));
//		stack = stack->next;
//	}
//}
////ջ�������
//void InvertedLinkList(stack stack) {
//	if (stack->next->next) {
//		InvertedLinkList(stack->next);
//	}
//	printf("%d ", (stack->next->elem));
//}
////��ջ����
//void PushLinkStack(stack *stack, ElemType elem) {
//	stacknode* node = (stacknode*)malloc(sizeof(stacknode));
//	node->elem = elem;
//	node->next = (*stack)->next;
//	(*stack)->next = node;
//}
////��ջ����
//void PopLinkStack(stack *stack, ElemType *elem) {
//	//printf("%d ", (*stack)->next->elem);
//	*elem = (*stack)->next->elem;
//	if ((*stack)->next != NULL) {
//		(*stack)->next = (*stack)->next->next;
//	}
//}
////ȡջ��Ԫ��
//ElemType getStackTopElem(stack stack) {
//	return stack->next->elem;
//}
//
//int main(void) {
//	ElemType elem;
//	stack stack;
//	InitLinkStack(&stack);
//	CreateLinkStack(&stack);
//	PushLinkStack(&stack, 4);
//	//TraversalLinkStack(stack);
//	//PopLinkStack(&stack, &elem);
//	//TraversalLinkStack(stack);
//	//printf("%d ", elem);
//	InvertedLinkList(stack);
//	return 0;
//}
