#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[21];
    int num;
} pokemon;

int compare(const void* a, const void* b) {
    return strcmp(((pokemon*)a)->name, ((pokemon*)b)->name);
}

int binarySearch(pokemon* arr, int size, const char* target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid].name, target);
        if (cmp == 0) return mid;
        else if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    pokemon* list = (pokemon*)malloc(n * sizeof(pokemon));
    pokemon* arr = (pokemon*)malloc(n * sizeof(pokemon));

    for (int i = 0; i < n; i++) {
        scanf("%20s", list[i].name);  // 수정: %20s → 입력 길이 제한, 이전 코드는 %s → 버퍼 오버플로우 위험
        list[i].num = i + 1;
        arr[i] = list[i];
    }

    qsort(arr, n, sizeof(pokemon), compare);

    char op[21];
    for (int i = 0; i < m; i++) {
        scanf("%20s", op);  // 수정: %20s → 안전하게 입력, 이전 코드는 %s

        if (op[0] >= '0' && op[0] <= '9') {
            int num = atoi(op);
            if (num >= 1 && num <= n)        // 수정: 범위 체크 추가, 이전 코드는 체크 안 함 → list[num-1]에서 Access Violation 가능
                printf("%s\n", list[num - 1].name);
        }
        else {
            int idx = binarySearch(arr, n, op);
            if (idx != -1)                  // 수정: 존재하지 않으면 출력 안 함
                printf("%d\n", arr[idx].num);
        }
    }

    free(list);
    free(arr);
    return 0;
}
