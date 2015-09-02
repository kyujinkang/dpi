#include <iostream>

using namespace std;

#if 0

void selectionSort(int base, int *input, int length);
int findMin(int base, int target, int *input, int length);

int main(void) {
	int input[] = { 7,5,4,2,1,3 };
	selectionSort(0, input, 6);

	for (int i = 0; i < 6; i++) {
		cout << input[i];
		if (i != 5) {
			cout << ", ";
		}
	}
	cout << endl;
	return 0;
}

void selectionSort(int base, int *input, int length) {
	int minIndex = 0;
	int target = 0;
	int temp = 0;

	if (base == length) {
		return;
	}
	target = input[base];
	minIndex = findMin(base, base + 1, input, length);
	if (target > input[minIndex]) {
		temp = input[base];
		input[base] = input[minIndex];
		input[minIndex] = temp;
	}
	selectionSort(base + 1, input, length);
}

int findMin(int base, int target, int *input, int length) {
	int minIndex = base;

	if (target == length) {
		return minIndex;
	}

	if (input[minIndex] > input[target]) {
		minIndex = target;
	}
	minIndex = findMin(minIndex, target + 1, input, length);

	return minIndex;
}

#endif


int main(void) {
	int line[10] = { -1, 3, -9, 6, 7, -6, 1, 5, 4, -2 };
	int i = 0, j = 0;
	int c = 0;
	int sum = -1;

	for (i = 0; i < (1 << 10); i++) {
		for (j = 0; j < 10; j++) {
			if (i & (1 << j)) {
				sum += line[j];
			}
		}
		if (sum == 0) {
			for (j = 0; j < 10; j++) {
				if (i & (1 << j)) {
					cout << line[j] << ' ';
				}
			}
			cout << ':' << sum << endl;
		}
		sum = 0;
	}

	return 0;
}