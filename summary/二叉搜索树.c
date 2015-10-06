//shenlei 2015 09 20
#include<stdio.h>
#include<stdlib.h>
typedef int Elem;
typedef struct BSTNode {
	Elem data;
	struct  BSTNode* lchild;
	struct  BSTNode* rchild;
}BSTNode,*BSTree;

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
//BST的元素查找，如果找到则返回指针，未找到返回NULL
void BSTFind(BSTree tree, Elem elem,BSTree *child) {
	if (tree->data == elem)
		*child = tree;
	if (tree->data > elem)
	 BSTFind(tree->lchild, elem, child);
	if (tree->data < elem)
	 BSTFind(tree->rchild, elem, child);
}

//BST父节点查找，未找到返回NULL
BSTree BSTFindFather(BSTree bst, Elem elem, BSTNode *f1, BSTree *f){
//f1为中间参数，用于求f,初始设为NULL，其目的是跟踪查找路径上访问的当前节点的父节点（即上一个访问节点）{
	if (bst == NULL)
	{
		*f = NULL;
		return NULL;
	}
	else if (elem == bst->data)
	{
		*f = f1;
		return bst;
	}
	else if (elem < bst->data)
		 BSTFindFather(bst->lchild, elem, bst, f);
	else
		 BSTFindFather(bst->rchild, elem, bst, f);
}


//查找最右节点
BSTree RightTree(BSTree tree) {
	if (!tree->rchild)
		return tree;
	while (tree->rchild) {
		tree = tree->rchild;
	}
	return tree;
}

BSTDelete(BSTree *tree, Elem elem) {
	BSTree child = NULL; BSTree father = NULL;
	BSTFind(*tree, elem, &child);
	if (child) {
		BSTFindFather(*tree, elem,NULL, &father);
		//lchild=rchild=NULL,直接删除
		if (child->lchild == NULL&&child->rchild == NULL) {
			free(child);
			father->lchild = father->rchild = NULL;
		}
		else {
			if (child->lchild == NULL && child->rchild != NULL) {
				if (father->data > child->data) {
					father->lchild = child->rchild;
				}
				else {
					father->rchild = child->rchild;
				}
			}
			else {
				if (child->rchild == NULL && child->lchild != NULL) {
					if (father->data > child->data) {
						father->lchild = child->lchild;
					}
					else {
						father->rchild = child->lchild;
					}
				}
				else {
					if (child->rchild != NULL && child->lchild != NULL) {
						BSTree rightree = NULL;
						if (rightree = RightTree(child->lchild)) {
							rightree->rchild = child->rchild;
							if (father == NULL) {
								*tree = child->lchild;
							}
							else {
								if (father->data > child->data) {
									father->lchild = child->lchild;
								}
								else {
									father->rchild = child->lchild;
								}
							}
							free(child);
						}
					}
				}
			}
				}

	}
}
BSTPreTravserse(BSTree tree) {
	if (tree != NULL) {
		printf("%d    ", tree->data);
		BSTPreTravserse(tree->lchild);
		BSTPreTravserse(tree->rchild);
	}
}
BSTMidTravserse(BSTree tree) {
	if (tree != NULL) {
		BSTMidTravserse(tree->lchild);
		printf("%d    ", tree->data);
		BSTMidTravserse(tree->rchild);
	}
}
int max = 0;
int BSTDepth(BSTree tree,int i) {
	if (tree != NULL) {
		if(i+1>max){
			max = i + 1;
		}
		BSTDepth(tree->lchild, i + 1);
		BSTDepth(tree->rchild, i + 1);
		return max;
	}
	
}

void Switch(int* x, int* y) {
	int tmp = *x;
	 *x = *y;
	 *y = tmp;
}

int Partition(int a[], int low, int high) {
	int pk = a[low];
	while (low < high) {
		while (low<high && (a[high]>pk))high--;
		Switch(&a[low], &a[high]);
		while (low < high && (a[low] < pk))low++;
		Switch(&a[low], &a[high]);
	}
	return low;
}


//快速排序
Qsort(int a[], int low, int high) {
	if (low < high) {
		int pk = Partition(a, low, high);
		Qsort(a, low, pk-1);
		Qsort(a, pk+1, high);
	}
}

int main(void) {
	BSTree tree = NULL;
	int a[9]= { 16,8,4,3,6,10,9,46,97 };
	for (int i = 0; i < 9; i++) {
		BSTInsert(&tree, a[i]);
	}
	BSTDelete(&tree, 16);
	BSTMidTravserse(tree);
	//int max = BSTDepth(tree,0);
	//printf("\nMaxBSTDepth = %d \n", max);
	//Qsort(a, 0, 5);
	/*for (int i = 0; i < 6; i++) {
		printf("%d ", a[i]);
	}*/
}