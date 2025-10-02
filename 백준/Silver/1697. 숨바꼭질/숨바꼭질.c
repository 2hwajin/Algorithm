#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000
#define SIZE 100001

int dist[SIZE];
int q[SIZE];
int front, rear;

int bfs(int N, int K) {
	if (N >= K) return N - K;
	memset(dist, -1, sizeof(dist));
	front = rear = 0;

	q[rear++] = N;
	dist[N] = 0;

	while (front < rear) {
		int x = q[front++];
		int next[3] = { x - 1, x + 1, x * 2 };
		for (int i = 0; i < 3; i++) {
			int nx = next[i];
			if (nx < 0 || nx > MAX) continue;
			if (dist[nx] != -1) continue;
			dist[nx] = dist[x] + 1;
			q[rear++] = nx;
			if (nx == K) return dist[nx];
		}
	}
	return dist[K];
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	int ans = bfs(N, K);
	printf("%d\n", ans);
	return 0;
}