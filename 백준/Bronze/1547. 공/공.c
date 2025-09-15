#include <stdio.h>

int main() {
	int M;
	int x, y;

	int ball = 1; // 공의 초기 위치

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		if (ball == x) {
			ball = y;
		}
		else if (ball == y) {
			ball = x;
		}
	}

	printf("%d\n", ball);
	return 0;
}