#include <stdio.h>
#include <stdlib.h>

// qsort에 사용할 비교 함수
int cmp(const void* a, const void* b) {
    int x = *(int*)a, y = *(int*)b;
    return (x > y) - (x < y);  // x<y면 -1, x==y면 0, x>y면 1
}

// 이진 탐색 함수 (있으면 1, 없으면 0 반환)
int binary_search(int* arr, int n, int target) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;  // 중앙 인덱스 선택
        if (arr[mid] == target) return 1;     // 찾음
        else if (arr[mid] < target) l = mid + 1;  // 오른쪽 탐색
        else r = mid - 1;                       // 왼쪽 탐색
    }
    return 0;  // 끝까지 못 찾으면 0
}

int main() {
    int N, M;
    scanf("%d", &N);

    // A 배열 입력
    int* A = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    // A를 정렬해야 이진 탐색 가능
    qsort(A, N, sizeof(int), cmp);

    // X 배열 입력
    scanf("%d", &M);
    int* X = malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++) scanf("%d", &X[i]);

    // X[i]가 A 안에 있는지 확인 → 있으면 1, 없으면 0 출력
    for (int i = 0; i < M; i++) {
        printf("%d\n", binary_search(A, N, X[i]));
    }

    // 동적 메모리 해제
    free(A); 
    free(X);
}
