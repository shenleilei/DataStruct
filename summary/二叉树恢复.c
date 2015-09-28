#include<stdio.h>
#define MAX_SIZE 100
int IndexOf(char prev[], char target) {
	int i = 0;
	while (prev[i] != '\0'&&prev[i] != target) {
		i++;
	}
	return i;
}

int IndexOfString(char prev[], char mid[], int low, int high) {
	int min_index = MAX_SIZE; int index;
	for (int i = low; i <= high; i++) {
		if (IndexOf(prev, mid[i]) < min_index) {
			min_index = IndexOf(prev, mid[i]);
			index = i;
		}
	}
	return index;
}
Switch(char mid[], int low, int index, int high) {
	char tmp[MAX_SIZE]; int k = low;
	for (int i = index+1; i <= high; i++,k++) {
		tmp[k] = mid[i];
	}
	tmp[k++] = mid[index];
	for (int i = low; i < index; i++,k++) {
		tmp[k] = mid[i];
	}
	for (int m = low; m <= high; m++)
		mid[m] = tmp[m];
}


trial(char prev[], char mid[], int low, int high) {
	if (low < high) {
		int index = IndexOfString(prev, mid,low,high);
		Switch(mid, low, index, high);
		//printf("%s ", mid);
		trial(prev, mid, 0,low-high-(index+1));
		trial(prev, mid, high-(index-1-low), high);
	}
}

int main(void) {
	char prev[5]= "ABCDE";
	char mid[5]= "BCAED";
	trial(prev, mid, 0, 4);
	for (int i = 0; i < 5;i++)
	printf("%c ",mid[i]);
}