#include <stdio.h>
#include <string.h>

int isVPS(const char* str) {
	int count = 0;
	for(int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(') count++;
		else if (str[i] == ')') count--;
		
		if (count < 0) return 0; // 닫는 괄호가 더 많음
	}
	return count == 0; // 모든 괄호가 짝을 이룸
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		char str[51];   // 괄호 문자열 저장
		scanf("%s", str);

		if (isVPS(str))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}