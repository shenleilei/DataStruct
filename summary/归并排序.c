#define MAX_LENGTH 100
#include<stdio.h>
Msort(int a[], int low, int mid, int high) {
	/*
	iָ��ǰ�벿�֣�jָ���벿�֣�kָ���´���������
	*/
	int i = low; int j = mid + 1; int k = low;
	int c[MAX_LENGTH];
	while ((i <= mid) && j <= high) {
		if (a[i] >= a[j]) {
			c[k] = a[j];
			j++;
		}
		else {
			c[k] = a[i];
			i++;
		}
		k++;
	}
	//�˴���ʾ��벿���Ѿ�����c���飬��ǰ�벿��δ����Ĳ��뼴��
	if (i <= mid) {
		for (; i <= mid; i++) {
			c[k] = a[i];
			k++;
		}
	}
	if (j <= high) {
		for (; j <= high; j++) {
			c[k] = a[j];
			k++;
		}
	}
	//��C[k]���Ƶ�a��
	for (int i = low; i <= high; i++) {
		a[i]= c[i];
	}
}
void Merge(int a[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		Merge(a, low, mid);
		Merge(a, mid+1, high);
		Msort(a, low, mid, high);
	}
}
int main(void) {
	int a[7] = { 49,38,65,97,76,13,27 };
	Merge(a, 0 , 6);
	for (int i = 0; i < 7; i++) {
		printf("%d ", a[i]);
	}
}