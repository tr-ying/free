#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct HashNode {
    int key;
    int value;
};

struct HashTable {
    struct HashNode *table;
    int size;
};

unsigned int hash(int key) {
    return key % TABLE_SIZE;
}

unsigned int doubleHash(int key) {
    return 1 + (key % (TABLE_SIZE - 1));
}

void initHashTable(struct HashTable *hashTable) {
    hashTable->size = TABLE_SIZE;
    hashTable->table = (struct HashNode *)malloc(sizeof(struct HashNode) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i].key = -1;
        hashTable->table[i].value = -1;
    }
}

void insertLinearProbing(struct HashTable *hashTable, int key, int value) {
    unsigned int index = hash(key);
    while (hashTable->table[index].key != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable->table[index].key = key;
    hashTable->table[index].value = value;
}

void insertDoubleHashing(struct HashTable *hashTable, int key, int value) {
    unsigned int index = hash(key);
    unsigned int step = doubleHash(key);
    while (hashTable->table[index].key != -1) {
        index = (index + step) % TABLE_SIZE;
    }
    hashTable->table[index].key = key;
    hashTable->table[index].value = value;
}

void insertQuadraticProbing(struct HashTable *hashTable, int key, int value) {
    unsigned int index = hash(key);
    unsigned int step = 1;
    unsigned int i = 1;
    while (hashTable->table[index].key != -1) {
        index = (index + step * i) % TABLE_SIZE;
        i++;
    }
    hashTable->table[index].key = key;
    hashTable->table[index].value = value;
}

void displayHashTable(struct HashTable *hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Slot %d: Key = %d, Value = %d\n", i, hashTable->table[i].key, hashTable->table[i].value);
    }
    printf("\n");
}

int main() {
    struct HashTable linearProbingTable, doubleHashingTable, quadraticProbingTable;
    initHashTable(&linearProbingTable);
    initHashTable(&doubleHashingTable);
    initHashTable(&quadraticProbingTable);

    int choice, key, value;

    while (1) {
        printf("Collision Handling Techniques:\n");
        printf("1. Linear Probing\n");
        printf("2. Double Hashing\n");
        printf("3. Quadratic Probing\n");
        printf("4. Display Hash Tables\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value for Linear Probing: ");
                scanf("%d %d", &key, &value);
                insertLinearProbing(&linearProbingTable, key, value);
                break;
            case 2:
                printf("Enter key and value for Double Hashing: ");
                scanf("%d %d", &key, &value);
                insertDoubleHashing(&doubleHashingTable, key, value);
                break;
            case 3:
                printf("Enter key and value for Quadratic Probing: ");
                scanf("%d %d", &key, &value);
                insertQuadraticProbing(&quadraticProbingTable, key, value);
                break;
            case 4:
                displayHashTable(&linearProbingTable);
                displayHashTable(&doubleHashingTable);
                displayHashTable(&quadraticProbingTable);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

/*
1
4 40
2
7 70
3
3 70
4
*/