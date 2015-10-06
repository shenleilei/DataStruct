#pragma warning(disable:4996)
#include<stdio.h>
#define MAX_BAG_NUM  20

int max(int x,int y) {
	return x > y ? x : y;
}
KnapSack(int weight[],int value[],int f[MAX_BAG_NUM+1][MAX_BAG_NUM+1],int bagnum,int C){
	//for (int i = 0; i <=bagnum; i++)
	//	f[i][0] = 0;
	//for (int j = 0; j <= C; j++)
	//	f[0][j] = 0;
	for (int i = 1; i <= bagnum; i++) {
		for (int j = 1; j <= C; j++) {
			if (weight[i] > j) {
				f[i][j] = f[i - 1][j];
			}
			else
			{
				f[i][j] = max( f[i - 1][j],f[i - 1][j - weight[i]]+value[i] );
			}
		}
	}
}

//�ݹ��ҵ���ѡ�е�����
Trial(int f[MAX_BAG_NUM+1][MAX_BAG_NUM+1], int x[], int weight[], int i, int j) {
	if (i > 0 && j > 0) {
		if (f[i][j] != f[i - 1 ][j]) {
			x[i] = 1;
			Trial(f, x, weight, i - 1, j - weight[i]);
		}
		else {
			Trial(f, x, weight, i - 1, j);
		}
	}
}
int main(void) {
	int weight[MAX_BAG_NUM+1] = {0};
	int value[MAX_BAG_NUM+1] = {0};
	int x[MAX_BAG_NUM+1] = {0};
	int f[MAX_BAG_NUM+1][MAX_BAG_NUM+1]={ { 0 } };
	
	//��ʼ����ر���
	int C;//������
	printf("������������");
	scanf("%d", &C);
	printf("�������������");
	int bagnum;//��������
	scanf("%d", &bagnum);
	for (int i = 1; i <= bagnum; i++) {
		printf("�����%d����������:",i);
		scanf("%d",&weight[i]);
	}
	for (int i = 1; i <= bagnum; i++) {
		printf("�����%d�����ļ�ֵ:", i);
		scanf("%d", &value[i]);
	}
	KnapSack(weight, value, f, bagnum, C);
	Trial(f, x,weight, bagnum, C);
	printf("����Ҫ��İ��ĵı�ţ��������ͼ�ֵ�ֱ��ǣ�\n");
	printf("���        ����      ��ֵ\n");
	for (int i = 0; i <= bagnum; i++) {
		if(x[i]==1)
		printf("  %d          %d          %d\n",i,weight[i],value[i]);
	}
}