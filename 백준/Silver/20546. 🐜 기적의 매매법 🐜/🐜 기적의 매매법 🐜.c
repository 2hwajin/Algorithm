#include <stdio.h>

int main() {
	int B; // 초기 자산
	int price[14]; // 14일간의 주가
	int cashB, cntB; // BNP 현금 자산, 주식 자산
	int cashT, cntT; // TIMING 현금 자산, 주식 자산

	scanf("%d", &B);
	for(int i = 0; i < 14; i++) {
		scanf("%d", &price[i]);
	}

	cashB = B; cntB = 0;
	cashT = B; cntT = 0;

	for(int i = 0; i < 14; i++) {
		if(cashB >= price[i]) {
			cntB += cashB / price[i];
			cashB -= cntB * price[i];
		}
	} // BNP

	for (int i = 3; i < 14; i++) {
		if (price[i - 3] > price[i - 2] && price[i - 2] > price[i - 1] && price[i - 1] > price[i]) {
			if (cashT >= price[i]) {
				cntT += cashT / price[i];
				cashT -= cntT * price[i];
			}
		}
		else if (price[i - 3] < price[i - 2] && price[i - 2] < price[i - 1] && price[i - 1] < price[i]) {
			if (cntT > 0) {
				cashT += cntT * price[i];
				cntT = 0;
			}
		}
	} // TIMING

	int finalB = cashB + cntB * price[13];
	int finalT = cashT + cntT * price[13];

	if(finalB > finalT) {
		printf("BNP\n");
	}
	else if(finalB < finalT) {
		printf("TIMING\n");
	}
	else {
		printf("SAMESAME\n");
	}

	return 0;
}