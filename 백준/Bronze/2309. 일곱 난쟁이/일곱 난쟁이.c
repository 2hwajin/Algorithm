#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b); // 오름차순
} // qsort compare function

int main() {
    int sum = 0;
    int arr[100] = {};
    int n, count = 0;

    while (scanf("%d", &n) != EOF) { 
        arr[count++] = n;
    }

    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }

    int remove_i = -1, remove_j = -1;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sum - (arr[i] + arr[j]) == 100) {
                remove_i = i;
                remove_j = j;
                break;
            }
        }
        if (remove_i != -1) break;
    }

    int res[7], idx = 0;
    for (int i = 0; i < count; i++) {
        if (i == remove_i || i == remove_j) continue;
        res[idx++] = arr[i];
    }

	qsort(res, 7, sizeof(int), compare);

    for (int i = 0; i < 7; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}