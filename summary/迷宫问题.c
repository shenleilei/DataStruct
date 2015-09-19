#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int x;//������
	int y;//������
}ElemType;
ElemType firstelem = { 0,0 };
int xShift[4] = { 0,0,-1,1 };  //����λ������ڵ�ǰλ�õ�x����  
int yShift[4] = { -1,1,0,0 };  //����λ������ڵ�ǰλ�õ�y����  
int last= 4;

typedef struct stacknode {
	ElemType elem;
	struct stacknode* next;
}stacknode, *stack;

InitLinkStack(stack *stack) {
	*stack = (stacknode*)malloc(sizeof(stacknode));
	stacknode* node = (stacknode*)malloc(sizeof(stacknode));
	node = NULL;
	(*stack)->next = node;

}
//ջ�ı���
TraversalLinkStack(stack stack) {
	while (stack->next != NULL) {
		printf("(%d %d)<-", (stack->next->elem).x,(stack->next->elem).y);
		stack = stack->next;
	}
}
//ջ�������
void InvertedLinkList(stack stack) {
	if (stack->next->next) {
		InvertedLinkList(stack->next);
	}
	printf("(%d,%d) ", (stack->next->elem).x, (stack->next->elem).y);
}
//��ջ����
PushLinkStack(stack *stack, ElemType elem) {
	stacknode* node = (stacknode*)malloc(sizeof(stacknode));
	node->elem = elem;
	node->next = (*stack)->next;
	(*stack)->next = node;
}
//��ջ����
PopLinkStack(stack *stack) {
	//printf("%d ", (*stack)->next->elem);
	if ((*stack)->next != NULL) {
		(*stack)->next = (*stack)->next->next;
	}
}
//ȡջ��Ԫ��
ElemType getStackTopElem(stack stack) {
	return stack->next->elem;
}

void Traial(int a[5][5],ElemType elem,stack* stack) {
	int i;                    ///��̽�����һλ��  
	if (elem.x == last&&elem.y == last) {
		InvertedLinkList(*stack);
		printf("\n");
	}
	else {
		for (i = 0; i < 4;i++){
			if (a[elem.x][elem.y] == 0 && elem.x >= 0 && elem.x <= 4 && elem.y >= 0 && elem.y <= 4) {
				a[elem.x][elem.y] = 2;
				PushLinkStack(stack, elem);
				elem.x = elem.x + xShift[i];
				elem.y = elem.y + yShift[i];
				Traial(a,elem, stack);
				elem.x = elem.x - xShift[i];
				elem.y = elem.y - yShift[i];
				a[elem.x][elem.y] = 0;
				PopLinkStack(stack);
			}
		}	
	}
}

int main(void) {
	int a[5][5] = {
		{ 0, 1, 0, 0, 0 },
		{ 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0 }
	};
	stack stack;
	InitLinkStack(&stack);
	Traial(a,firstelem,&stack);
}

