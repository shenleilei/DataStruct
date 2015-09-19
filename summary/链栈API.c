//#pragma warning(disable:4996)
//#include<stdio.h>
//#include<stdlib.h>
//typedef int ElemType;
//typedef struct stacknode {
//	ElemType elem;
//	struct stacknode* next;
//}stacknode, *stack;
////初始化
//void InitLinkStack(stack *stack) {
//	*stack = (stacknode*)malloc(sizeof(stacknode));
//	stacknode* node = (stacknode*)malloc(sizeof(stacknode));
//	node = NULL;
//	(*stack)->next = node;
//}
////建栈
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
////栈的遍历
//void TraversalLinkStack(stack stack) {
//	while (stack->next != NULL) {
//		printf("%d   ", (stack->next->elem));
//		stack = stack->next;
//	}
//}
////栈反向输出
//void InvertedLinkList(stack stack) {
//	if (stack->next->next) {
//		InvertedLinkList(stack->next);
//	}
//	printf("%d ", (stack->next->elem));
//}
////入栈操作
//void PushLinkStack(stack *stack, ElemType elem) {
//	stacknode* node = (stacknode*)malloc(sizeof(stacknode));
//	node->elem = elem;
//	node->next = (*stack)->next;
//	(*stack)->next = node;
//}
////出栈操作
//void PopLinkStack(stack *stack, ElemType *elem) {
//	//printf("%d ", (*stack)->next->elem);
//	*elem = (*stack)->next->elem;
//	if ((*stack)->next != NULL) {
//		(*stack)->next = (*stack)->next->next;
//	}
//}
////取栈顶元素
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
