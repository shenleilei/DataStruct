#include<stdio.h>
#include<stdlib.h>

#define LH 1	//左高
#define EH 0	//平衡
#define RH -1	//右高
typedef int Elem;
typedef struct AVLNODE
{
	Elem elem;
	int bf;
	struct AVLNODE *lchild;
	struct AVLNODE *rchild;
}AVLNODE,*AVLTree;

//右转
R_Rotate(AVLTree* tree) {
	AVLNODE *lc = (*tree)->lchild;
	(*tree)->lchild = lc->rchild;
	lc->rchild = (*tree);
	(*tree) = lc;
}
//左转
L_Rotate(AVLTree* tree) {
	AVLNODE *rc = (*tree)->rchild;
	(*tree)->rchild = rc->lchild;
	rc->lchild = (*tree);
	(*tree) = rc;
}

LeftBalance(AVLTree* tree) {
	AVLTree rd = NULL;
	AVLTree lc = (*tree)->lchild;
	switch (lc->bf) {
	case LH:
		//这是因为挂在T的左子树的左子树上，且因为这次挂导致之前的平衡被破坏，所以原来的左子树
		//必定是LH或者RH，所以整个左子树必须先向右绕
		lc->bf = (*tree)->bf=EH; R_Rotate(tree); break;
	case RH:
		rd = lc->rchild;
		switch (rd->bf)
		{
		case LH:(*tree)->bf = RH; lc->bf = EH; break;
		case EH:(*tree)->bf = EH; lc->bf = EH; break;
		case RH:(*tree)->bf = EH; lc->bf = LH; break;
		default:
			break;
		}
		rd->bf = EH;
		L_Rotate(&(lc));
		R_Rotate(tree);
	}
}

RightBalance(AVLTree* tree) {
	AVLTree ld = NULL;
	AVLTree rc = (*tree)->rchild;
	switch (rc->bf) {
	case RH:
		//这是因为挂在T的右子树上，且因为这次挂导致之前的平衡被破坏，所以原来的右子树
		//必定是LH或者RH，所以整个右子树必须先向左绕
		rc->bf = (*tree)->bf=EH; L_Rotate(tree); break;
	case LH:
		ld = rc->lchild;
		switch (ld->bf)
		{
		case LH:(*tree)->bf = EH; rc->bf = RH; break;
		case EH:(*tree)->bf = EH; rc->bf = EH; break;
		case RH:(*tree)->bf = LH; rc->bf = EH; break;
		default:
			break;
		}
		ld->bf = EH;
		R_Rotate(&(rc));
		L_Rotate(tree);
	}
}
AVLInsert(AVLTree *tree,Elem elem,int* taller){
	if ((*tree) == NULL) {
		*tree = (AVLNODE*)malloc(sizeof(AVLNODE));
		(*tree)->lchild = (*tree)->rchild = NULL;
		(*tree)->elem = elem;
		(*tree)->bf = EH;
		(*taller) = 1;
	}
	else {
		if ((*tree)->elem == elem) {
			return 0;
		}
		if ((*tree)->elem > elem)
		{
			AVLInsert(&((*tree)->lchild), elem, taller);
			//此时判断树的左右高度关系
			if (taller) {
				switch ((*tree)->bf)
				{
				case LH:
					LeftBalance(tree); *taller = 0; break;
				case EH:
					(*tree)->bf = LH; *taller = 1; break;
				case RH:
					(*tree)->bf = EH; *taller = 0; break;
				default:
					break;
				}
			}
	}
		if ((*tree)->elem < elem)
		{
			AVLInsert(&((*tree)->rchild), elem, taller);
			//此时判断树的左右高度关系
			if (taller) {
				switch ((*tree)->bf)
				{
				case RH:
					RightBalance(tree); *taller = 0; break;
				case EH:
					(*tree)->bf = RH; *taller = 1; break;
				case LH:
					(*tree)->bf = EH; *taller = 0; break;
				default:
					break;
				}
			}
		}
	}
}
BSTMidTravserse(AVLTree tree) {
	if (tree != NULL) {
		BSTMidTravserse(tree->lchild);
		printf("%d    ", tree->elem);
		BSTMidTravserse(tree->rchild);
	}
}
BSTPreTravserse(AVLTree tree) {
	if (tree != NULL) {
		printf("%d    ", tree->elem);
		BSTPreTravserse(tree->lchild);
		BSTPreTravserse(tree->rchild);
	}
}
int main(void) {
	AVLTree tree = NULL;
	int taller=0;
	int a[9] = {22,24,26};
	for (int i = 0; i < 3; i++) {
		AVLInsert(&tree, a[i],&taller);
	}
	BSTMidTravserse(tree);
	printf("\n");
	BSTPreTravserse(tree);
}