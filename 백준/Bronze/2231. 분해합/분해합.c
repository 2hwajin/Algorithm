#include <stdio.h>
#include <string.h>

int decomposition(int N) {
	char str[20];
	sprintf(str, "%d", N);
	int sum = N;
	for (int i = 0; i < strlen(str); i++) {
		sum += (str[i] - '0');
	}
	return sum;
}

int repete(int N) {
	for (int i = 1; i < N; i++) {
		if (decomposition(i) == N) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
}

int main() {
	int N;
	scanf("%d", &N);
	repete(N);
	return 0;
}