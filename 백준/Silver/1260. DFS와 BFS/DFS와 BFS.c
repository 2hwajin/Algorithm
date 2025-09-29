#include <stdio.h>
#include <stdlib.h>

int graph[1001][1001] = { 0, };
int edges[1001] = { 0, };
int visited[1001] = { 0, };
int queue[1001] = { 0, }; // BFS용 큐
int front = 0, rear = 0;

int cmp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void dfs(int v) {
	visited[v] = 1;
	printf("%d ", v);

	for(int i = 0; i < edges[v]; i++) {
		int next = graph[v][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int v) {
	front = rear = 0;
	visited[v] = 1;
	queue[rear++] = v;

	while (front < rear) {
		int v = queue[front++];
		printf("%d ", v);

		for (int i = 0; i < edges[v]; i++) {
			int next = graph[v][i];
			if (!visited[next]) {
				visited[next] = 1;
				queue[rear++] = next;
			}
		}
	}
}

int main() {
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a][edges[a]++] = b;
		graph[b][edges[b]++] = a;
	} // 간선 연결

	for (int i = 1; i <= N; i++) {
		qsort(graph[i], edges[i], sizeof(int), cmp);
	}

	// DFS
	dfs(V);

	printf("\n");

	// BFS
	for (int i = 1; i <= N; i++) visited[i] = 0; // DFS 이후 방문 초기화
	bfs(V);

	return 0;
}