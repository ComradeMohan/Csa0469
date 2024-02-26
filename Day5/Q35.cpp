#include <stdio.h>
#include <stdlib.h>

#define FILE_SIZE 10

int main() {
    int index_block[FILE_SIZE]; // Index block to store pointers to file blocks
    int file_blocks[FILE_SIZE]; // Simulated file blocks

    // Initialize file blocks with random data (for simulation purposes)
    for (int i = 0; i < FILE_SIZE; i++) {
        file_blocks[i] = rand() % 100; // Random data from 0 to 99
    }

    // Initialize index block to point to each file block
    for (int i = 0; i < FILE_SIZE; i++) {
        index_block[i] = i;
    }

    // Simulate reading the file by accessing blocks through the index block
    printf("Simulating reading the file:\n");
    for (int i = 0; i < FILE_SIZE; i++) {
        printf("Block %d: Data %d\n", i, file_blocks[index_block[i]]);
    }

    return 0;
}
