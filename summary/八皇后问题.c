#include<stdio.h>
#include<math.h>
#define MAX_LEN 8
int times=0;
print(int a[MAX_LEN][MAX_LEN]) {
	times++;
	for (int i = 0; i < MAX_LEN; i++) {
		for (int j = 0; j < MAX_LEN; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//判断是否处于同一条线
int IsSameLine(int a[MAX_LEN][MAX_LEN], int i, int j) {
	for (int m = 0; m < i; m++) {
		for (int k = 0; k < MAX_LEN; k++) {
			if (a[m][k] == 1 && (abs(i - m) == abs(k - j)||k==j)) {
				return 1;
			}
		}
	}
	return 0;
}


Trial(int a[MAX_LEN][MAX_LEN], int i) {
	if (i == MAX_LEN)
		print(a);
	int j = 0;
	for (; j < MAX_LEN ; j++) {
		if (!IsSameLine(a, i, j)) {
			//作为标记，1表示摆放
			a[i][j] = 1;
			i++;
			Trial(a, i);	
			//不满足要求之后，要恢复原值
			i--;
			a[i][j] = 0;
		}
	}
}
int main(void) {
	int a[MAX_LEN][MAX_LEN];
	for (int  i = 0; i < MAX_LEN; i++)
	{
		for (int j = 0; j < MAX_LEN; j++) {
			a[i][j] = 0;
		}
	}
	Trial(a, 0);
	printf("%d", times);
}