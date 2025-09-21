#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 100003 // 소수로 버킷 크기

typedef struct Node {
    char name[21];
    struct Node *next;
} Node;

Node *hash[HASH_SIZE] = {0};

unsigned int hash_func(const char *s) {
    unsigned int h = 0;
    for (int i = 0; s[i]; i++)
        h = (h * 31 + s[i]) % HASH_SIZE;
    return h;
}

void insert(const char *name) {
    unsigned int h = hash_func(name);
    Node *cur = hash[h];
    while (cur) {
        if (strcmp(cur->name, name) == 0) return; // 이미 존재
        cur = cur->next;
    }
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->next = hash[h];
    hash[h] = new_node;
}

void remove_name(const char *name) {
    unsigned int h = hash_func(name);
    Node *cur = hash[h], *prev = NULL;
    while (cur) {
        if (strcmp(cur->name, name) == 0) {
            if (prev) prev->next = cur->next;
            else hash[h] = cur->next;
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char temp_name[21], temp_state[11];
    for (int i = 0; i < n; i++) {
        scanf("%s %s", temp_name, temp_state);
        if (strcmp(temp_state, "enter") == 0) insert(temp_name);
        else remove_name(temp_name);
    }

    // 남은 사람 수 계산
    int count = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *cur = hash[i];
        while (cur) {
            count++;
            cur = cur->next;
        }
    }

    // 이름을 배열로 옮겨 정렬
    char **people = malloc(count * sizeof(char*));
    int idx = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *cur = hash[i];
        while (cur) {
            people[idx++] = cur->name;
            cur = cur->next;
        }
    }

    // qsort 역순
    int cmp(const void *a, const void *b) {
        char *s1 = *(char **)a;
        char *s2 = *(char **)b;
        return strcmp(s2, s1);
    }
    qsort(people, count, sizeof(char*), cmp);

    for (int i = 0; i < count; i++) printf("%s\n", people[i]);

    // 동적 메모리 해제
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *cur = hash[i];
        while (cur) {
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(people);

    return 0;
}
