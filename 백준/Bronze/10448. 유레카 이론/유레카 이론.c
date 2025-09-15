#include <stdio.h>
#include <stdlib.h>

int main() {
	int T; // 테스트 케이스 수
	scanf("%d", &T);
	int arr[1000];
	
	for (int i = 0; i < T; i++) {
		scanf("%d", &arr[i]); // 각 테스트 케이스의 수 입력
	}

	int max_value = arr[0];
	for (int i = 1; i < T; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
		}
	}

	int tri[1000]; // 삼각수 리스트 생성
	int count = 0;
	int k = 1;

	while (1) {
		int t = k * (k + 1) / 2; // 삼각수 공식 적용
		if (t > max_value) break;
		tri[count++] = t;
		k++;
	} // 가장 큰 수를 기준으로 작거나 같은 삼각수 리스트 생성

	for (int i = 0; i < T; i++) {
		int num = arr[i];
		int found = 0; // 삼각수 가능 시 1로 저장 위한 found 변수

		for (int a = 0; a < count && !found; a++) {
			for (int b = a; b < count && !found; b++) { // 삼각수 간 중복 허용 (a<=b)
				int sum = tri[a] + tri[b];
				int remain = num - sum;

				// remain이 양수이고 삼각수인지 확인
				for (int c = 0; c < count; c++) {
					if (tri[c] == remain) {
						found = 1;
						break;
					}
				}
			}
		}

		printf("%d\n", found);
	}

	return 0;
}