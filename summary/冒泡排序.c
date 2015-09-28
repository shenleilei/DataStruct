#include<stdio.h>
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void BubbleSort(int a[],int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length-1; j++) {
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
		}
	}
}

int main(void) {
	int a[6] = { 6,2,4,1,5,9 };
	BubbleSort(a, 6);
	for (int i = 0; i < 6; i++) {
		printf("%d ", a[i]);
	}
}