#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int disk_size, head_position, num_requests, total_seek_time = 0;

    printf("Enter the size of the disk: ");
    scanf("%d", &disk_size);

    printf("Enter the initial head position: ");
    scanf("%d", &head_position);

    printf("Enter the number of disk I/O requests: ");
    scanf("%d", &num_requests);

    int requests[num_requests];

    printf("Enter the disk I/O request positions:\n");
    for (int i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    // Calculate total seek time
    for (int i = 0; i < num_requests; i++) {
        total_seek_time += abs(requests[i] - head_position);
        head_position = requests[i];
    }

    printf("Total seek time: %d\n", total_seek_time);

    return 0;
}
