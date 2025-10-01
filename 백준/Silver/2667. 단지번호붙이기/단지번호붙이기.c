#include <stdio.h>
#include <stdlib.h>

int graph[26][26];
int visited[26][26];
int N; // 정사각형 지도

// 상하좌우 
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int dfs(int x, int y) {
	visited[y][x] = 1; // [row][col]
	int size = 1; // 집 개수 카운트 

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (graph[ny][nx] == 1 && !visited[ny][nx]) {
				size += dfs(nx, ny);
			}
		}
	}
	return size;
}

int cmp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char line[30];
		scanf("%s", line);
		for(int j = 0; j < N; j++) {
			graph[i][j] = line[j] - '0';
			visited[i][j] = 0;
		}
	}

	int sizes[625] = { 0, }; // 최대 25*25/1
	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(graph[i][j] == 1 && !visited[i][j]) {
				sizes[count] = dfs(j, i);
				count++;
			}
		}
	}
	qsort(sizes, count, sizeof(int), cmp);

	printf("%d\n", count);
	for(int i = 0; i < count; i++) {
		printf("%d\n", sizes[i]);
	}
	return 0;
}