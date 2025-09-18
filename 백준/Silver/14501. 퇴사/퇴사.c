#include <stdio.h>

int N;
int T[16];
int P[16];
int max = 0;

void work(int day, int profit) {
	if (day > N) {
		if (profit > max) max = profit;
		return;
	}

	if (day + T[day] <= N + 1) {
		work(day + T[day], profit + P[day]);
	}

	work(day + 1, profit);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &T[i], &P[i]);
	}

	work(1, 0);

	printf("%d\n", max);

	return 0;
}


