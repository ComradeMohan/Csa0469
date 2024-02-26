#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

// Structure to represent a disk block
typedef struct DiskBlock {
    int data;
    struct DiskBlock* next;
} DiskBlock;

// Structure to represent a file
typedef struct File {
    DiskBlock* firstBlock;
    DiskBlock* lastBlock;
} File;

// Array to represent the disk blocks
DiskBlock disk[MAX_BLOCKS];

// Function to initialize the disk blocks
void initializeDisk() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        disk[i].data = 0;
        disk[i].next = NULL;
    }
}

// Function to allocate a new block for a file
DiskBlock* allocateBlock(int data) {
    DiskBlock* block = (DiskBlock*)malloc(sizeof(DiskBlock));
    if (block == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    block->data = data;
    block->next = NULL;
    return block;
}

// Function to add a block to the end of a file
void addBlockToFile(File* file, int data) {
    DiskBlock* block = allocateBlock(data);
    if (file->firstBlock == NULL) {
        file->firstBlock = block;
        file->lastBlock = block;
    } else {
        file->lastBlock->next = block;
        file->lastBlock = block;
    }
}

// Function to display the contents of a file
void displayFile(File* file) {
    DiskBlock* currentBlock = file->firstBlock;
    while (currentBlock != NULL) {
        printf("%d ", currentBlock->data);
        currentBlock = currentBlock->next;
    }
    printf("\n");
}

int main() {
    initializeDisk();

    File file1 = {NULL, NULL};
    addBlockToFile(&file1, 1);
    addBlockToFile(&file1, 2);
    addBlockToFile(&file1, 3);

    File file2 = {NULL, NULL};
    addBlockToFile(&file2, 4);
    addBlockToFile(&file2, 5);

    printf("File 1: ");
    displayFile(&file1);

    printf("File 2: ");
    displayFile(&file2);

    return 0;
}
