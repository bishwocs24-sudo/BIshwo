#include <stdio.h>

#define m 10   /* Size of hash table */

int hashTable[m];

/* Hash function */
int hash(int key) {
    return key % m;
}

/* Insert key using linear probing */
void insert(int key) {
    int index = hash(key);

    while (hashTable[index] != -1) {
        index = (index + 1) % m;   /* Linear probing */
    }

    hashTable[index] = key;
}

/* Display hash table */
void display() {
    int i;
    printf("\nHash Table:\n");
    for (i = 0; i < m; i++) {
        if (hashTable[i] == -1)
            printf("%d : EMPTY\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key, i;

    /* Initialize hash table */
    for (i = 0; i < m; i++)
        hashTable[i] = -1;

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    printf("Enter 4-digit employee keys:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
