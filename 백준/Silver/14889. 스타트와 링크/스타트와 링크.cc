#include <stdio.h>
#include <stdlib.h>

int N;
int S[20][20];
int team[10];       // 조합 저장: 선택된 팀A 멤버 인덱스
int min = 1000000;  // 최소 차이값 초기화

// 두 팀의 능력치 차이를 계산하는 함수
void calc() {
    int startS = 0, linkS = 0;
    int idxS = 0, idxL = 0;
    int start[10], link[10];

    // ! team[]을 보고 팀A/팀B 나누기
    int used[20] = {0};
    for (int i = 0; i < N/2; i++) used[team[i]] = 1;

    for (int i = 0; i < N; i++) {
        if (used[i]) start[idxS++] = i;
        else link[idxL++] = i;
    }

    // ! i < j만 돌려서 중복 계산 제거
    for (int i = 0; i < N/2; i++) {
        for (int j = i + 1; j < N/2; j++) {
            startS += S[start[i]][start[j]] + S[start[j]][start[i]]; // ! 최적화
            linkS  += S[link[i]][link[j]] + S[link[j]][link[i]];   // ! 최적화
        }
    }

    int diff = abs(startS - linkS);
    if (diff < min) min = diff;

    // ! 최소 차이가 0이면 더 이상 탐색 필요 없음 → 조기 종료
    if (min == 0) {
        printf("0\n");
        exit(0); // ! 프로그램 바로 종료
    }
}

void combination(int startIdx, int depth) {
    if (depth == N/2) {
        calc();
        return;
    }
    for (int i = startIdx; i < N; i++) {
        team[depth] = i;
        combination(i + 1, depth + 1);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &S[i][j]);
        }
    }

    team[0] = 0;              // 첫 번째 팀원은 무조건 0번
    combination(1, 1);        // 나머지 멤버 선택 시작

    printf("%d\n", min);      // 최소 능력치 차이 출력
    return 0;
}