#include <stdio.h>
#include <stdlib.h>

int graph[1001][1001] = { 0, };
int edges[1001] = { 0, };
int visited[1001] = { 0, };

void dfs(int v) {
	visited[v] = 1;

	for (int i = 0; i < edges[v]; i++) {
		int next = graph[v][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u][edges[u]++] = v;
		graph[v][edges[v]++] = u;
	} // 간선 연결

	int count = 0;

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
			count++;
		}
	}

	printf("%d", count);

	return 0;
}