#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#define MAX_LEN 20
typedef struct {
	int length;
	int a[MAX_LEN];
}node;
//��һ�����������е�ֵ��������һ������������
IntStringcpy(node *dst, node src) {
	for (int i = 0; i < src.length; i++) {
		(*dst).a[i] = src.a[i];
	(*dst).length = src.length;
	}
}
Intcpy(node* dst, int num) {
	int length = (*dst).length;
	(*dst).a[length] = num;
	(*dst).length++;
}

LIS(int num[], node dp[],int length) {
	int i = 1, j = 0; dp[0].a[0] = num[0];
	for (; i < length; i++) {
		for (j=0; j < i; j++) {
			if ((num[j] < num[i]) && dp[i].length < dp[j].length+1) {
				//�ֽ�dp[j]�е�����a������dp[j]������dp[i]֮�С�
				IntStringcpy(&dp[i],dp[j]);
			}
		}
		//��ĳ��i�ڵ����֮��Ҳ�������dp������,ͬʱlength����1��
		Intcpy(&dp[i],num[j]);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	int array[MAX_LEN];
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	node dp[MAX_LEN];
	for (int i = 0; i < n; i++)
		dp[i].length = 1;

	LIS(array, dp, n);
	int max = dp[0].length;
	for (int i = 1; i < n; i++) {
		if (max < dp[i].length) {
			max=dp[i].length;
		}
	}
	for (int i = 0; i < n; i++) {
		if (dp[i].length == max) {
			for (int j = 0; j < max; j++) {
				printf("%d ", dp[i].a[j]);
			}
			printf("\n");
		}
	}

}