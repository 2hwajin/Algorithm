#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return (x > y) - (x < y);  // 오름차순 정렬
}

// lower bound: target 이상이 처음 나오는 위치
int lower_bound(int* arr, int n, int target) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] < target) l = mid + 1;
        else r = mid;
    }
    return l;
}

// upper bound: target 초과가 처음 나오는 위치
int upper_bound(int* arr, int n, int target) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] <= target) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
	int n, m;
	scanf("%d", &n);

	int* N = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &N[i]);
	}

	qsort(N, n, sizeof(int), cmp);

	scanf("%d", &m);
	int* M = malloc(m * sizeof(int));
    for(int i = 0; i < m; i++) {
        scanf("%d", &M[i]);
	}

    for (int i = 0; i < m; i++) {
        int count = upper_bound(N, n, M[i]) - lower_bound(N, n, M[i]);
        printf("%d ", count);
    }

	free(N);
	free(M);

	return 0;
}