#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int graph[51][51];
int visited[51][51];
int N, M;

// 상하좌우 
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dfs(int x, int y) {
	visited[y][x] = 1; // [row][col]

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < M && ny >= 0 && ny < N) { // 범위 체크
			if (graph[ny][nx] == 1 && !visited[ny][nx]) { // 땅이고 방문하지 않았으면
				dfs(nx, ny);
			}
		}
	}
}

int main(){
	int T, K;
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d %d", &M, &N, &K);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++){
				graph[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		for (int i = 0; i < K; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			graph[y][x] = 1;
		}
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] == 1 && !visited[i][j]) { // 땅이고 방문하지 않았으면
					dfs(j, i);
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}