#include <stdio.h>
#include <limits.h>

int N;
int nums[11];
int ops[10]; // 연산자 배열 (최대 10개)
int max_val = INT_MIN;
int min_val = INT_MAX;

// swap 함수
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 순열 생성 (Heap's algorithm)
void permute(int depth, int n) {
    if (depth == n) {
        // 계산 수행
        int result = nums[0];
        for (int i = 0; i < n; i++) {
            int op = ops[i];
            if (op == 0) result += nums[i+1];
            else if (op == 1) result -= nums[i+1];
            else if (op == 2) result *= nums[i+1];
            else {
                if (result < 0) result = -((-result) / nums[i+1]);
                else result /= nums[i+1];
            }
        }
        if (result > max_val) max_val = result;
        if (result < min_val) min_val = result;
        return;
    }

    for (int i = depth; i < n; i++) {
        swap(&ops[depth], &ops[i]);
        permute(depth + 1, n);
        swap(&ops[depth], &ops[i]);
    }
}

int main() {
    int count[4];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
    for (int i = 0; i < 4; i++) scanf("%d", &count[i]);

    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < count[i]; j++) {
            ops[k++] = i; // 연산자 채우기
        }
    }

    permute(0, N-1);

    printf("%d\n%d\n", max_val, min_val);
    return 0;
}
