#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#define MAX_LEN 20
typedef struct {
	int length;
	int a[MAX_LEN];
}node;
//��һ�����������е�ֵ��������һ������������
void IntStringcpy(node *dst, node src) {
	for (int i = 0; i < src.length; i++) {
		(*dst).a[i] = src.a[i];
		(*dst).length = src.length;
	}
}
void Intcpy(node* dst, int num) {
	int length = (*dst).length;
	(*dst).a[length] = num;
	(*dst).length++;
}

void LDS(int num[], node dp[], int n) {
	int i = n-2, j;
	dp[n - 1].a[0] = num[n - 1]; dp[n - 1].length = 1;
	for (; i >=0; i--) {
		for (j = n-1; j > i; j--) {
			if ((num[j] < num[i]) && dp[i].length < dp[j].length + 1) {
				//�ֽ�dp[j]�е�����a������dp[j]������dp[i]֮�С�
				IntStringcpy(&dp[i], dp[j]);
			}
		}
		//��ĳ��i�ڵ����֮��Ҳ�������dp������,ͬʱlength����1��
		Intcpy(&dp[i], num[j]);
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
		dp[i].length = 0;

	LDS(array, dp, n);
	int max = dp[n-1].length;
	for (int i = n-2; i >=0; i--) {
		if (max < dp[i].length) {
			max = dp[i].length;
		}
	}
	for (int i =n-1; i >=0; i--) {
		
		if (dp[i].length == max) {
			for (int j = max-1;j>=0; j--) {
				printf("%d ", dp[i].a[j]);
			}
			printf("\n");
		}
	}

}