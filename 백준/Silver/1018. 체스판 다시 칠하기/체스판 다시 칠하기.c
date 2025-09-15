#include <stdio.h>

// W로 시작하는 체스판 패턴
const char patternW[8][8] = {
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};

// B로 시작하는 체스판 패턴
const char patternB[8][8] = {
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	char arr[50][50] = { 0 };

	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i]); // 문자열로 입력받기
	}

	int ans = 64; // 최대 64칸

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int countW = 0;
			int countB = 0;

			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {
					if (arr[i + x][j + y] != patternW[x][y]) countW++;
					if (arr[i + x][j + y] != patternB[x][y]) countB++;
				}
			}
			ans = min(ans, min(countW, countB));
		}
	}
	printf("%d\n", ans);
	return 0;
}