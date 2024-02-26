#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100
#define RECORD_SIZE 50

// Structure to represent a record
typedef struct {
    char data[RECORD_SIZE];
} Record;

// Structure to represent the file
typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} File;

// Function to add a record to the file
void addRecord(File *file, const char *data) {
    if (file->num_records < MAX_RECORDS) {
        Record new_record;
        snprintf(new_record.data, RECORD_SIZE, "%s", data);
        file->records[file->num_records++] = new_record;
        printf("Record added successfully.\n");
    } else {
        printf("File is full. Cannot add more records.\n");
    }
}

// Function to read all records in the file
void readAllRecords(File *file) {
    printf("Records in the file:\n");
    for (int i = 0; i < file->num_records; i++) {
        printf("%d: %s\n", i + 1, file->records[i].data);
    }
}

int main() {
    File file;
    file.num_records = 0;

    int choice;
    char data[RECORD_SIZE];
    do {
        printf("\n1. Add Record\n");
        printf("2. Read All Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter record data: ");
                scanf("%s", data);
                addRecord(&file, data);
                break;
            case 2:
                readAllRecords(&file);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
