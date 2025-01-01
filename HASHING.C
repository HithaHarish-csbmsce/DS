#include <stdio.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Hash table is full\n");
            return;
        }
    }
    hashTable[index] = key;
}

void displayTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("[%d] -> NULL\n", i);
        } else {
            printf("[%d] -> %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int n, key;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    initializeTable();

    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    displayTable();
    return 0;
}
OUTPUT:
Enter the number of keys: 5
Enter the keys:
12
22
32
42
52
Hash Table:
[0] -> NULL
[1] -> NULL
[2] -> 12
[3] -> 22
[4] -> 32
[5] -> 42
[6] -> 52
[7] -> NULL
[8] -> NULL
[9] -> NULL
Enter the number of keys: 5
Enter the keys:
11
21
31
41
51
Hash Table:
[0] -> NULL
[1] -> 11
[2] -> 21
[3] -> 31
[4] -> 41
[5] -> 51
[6] -> NULL
[7] -> NULL
[8] -> NULL
[9] -> NULL
