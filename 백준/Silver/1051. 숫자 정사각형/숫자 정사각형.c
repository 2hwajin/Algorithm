#include <stdio.h>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

    int arr[50][50] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	int max_size = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 1; i + k < N && j + k < M; k++) {
                if (arr[i][j] == arr[i][j + k] &&
                    arr[i][j] == arr[i + k][j] &&
                    arr[i][j] == arr[i + k][j + k]) {
                    int area = (k + 1) * (k + 1);
                    if (area > max_size) max_size = area;
                }
            }
        }
    }

    printf("%d\n", max_size);
    return 0;

}