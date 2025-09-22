#include <stdio.h>

int main() {
	int n;
	int stack[100001];
	char op[200001]; // push, pop 2번의 연산 수행 가능
	int arr[100001]; // malloc 대신 정적 배열
	int top = -1;

	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int num = 1;
	int idx = 0;
	int operation = 0; // 0: push, 1: pop

	while (1) {
		if (top == -1 || stack[top] < arr[idx]) {
			stack[++top] = num++;
			op[operation++] = '+';
		}
		else if(stack[top] == arr[idx]) {
			top--;
			op[operation++] = '-';
			idx++;
			if (idx == n) break;
		}
		else {
			printf("NO\n");
			return 0;
		}
	}
	for(int i = 0; i < operation; i++) {
		printf("%c\n", op[i]);
	}
	return 0;
}