#include <stdio.h>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	float tt = 10; // 땡
	float kk = 0; // 끝
	float win = 0;

	if (N == M) {
		tt -= N;
		win = (153 - tt)/153;
	}
	else {
		kk = (N + M) % 10;
		for (int i = 1; i <= 10; i++) {
			for (int j = i + 1; j <= 10; j++) {
				if (kk > (i + j) % 10) {
					if (i == N && j == M) { // 자기 자신이면 패스
						continue;
					}
					else if (i == N || j == N || i == M || j == M) { // 하나가 겹칠 경우 2의 가중치 
						win += 2;
					}
					else {
						win += 4; // 둘 다 겹치지 않을 경우 4의 가중치
					}
				}
			}
		}
		win = win / 153;
	}
	printf("%.3f", win);
	return 0;
}