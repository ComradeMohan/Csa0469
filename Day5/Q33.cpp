#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FRAMES 10

int main() {
    int frames[MAX_FRAMES], pages[MAX_FRAMES], pageFaults = 0, hits = 0, n, m, i, j, k, l, idx;
    bool isFull;

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    printf("Enter the number of pages: ");
    scanf("%d", &m);

    printf("Enter the page reference string: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < n; i++) {
        frames[i] = -1;
    }

    for (i = 0; i < m; i++) {
        printf("\nPage %d:\n", pages[i]);
        isFull = true;

        for (j = 0; j < n; j++) {
            if (frames[j] == -1) {
                frames[j] = pages[i];
                isFull = false;
                break;
            } else if (frames[j] == pages[i]) {
                hits++;
                isFull = false;
                break;
            }
        }

        if (isFull) {
            pageFaults++;
            for (k = i + 1; k < m; k++) {
                for (l = 0; l < n; l++) {
                    if (frames[l] == pages[k]) {
                        frames[l] = -1;
                        break;
                    }
                }
                if (l < n) {
                    break;
                }
            }
            idx = l;
            frames[idx] = pages[i];
        }

        for (j = 0; j < n; j++) {
            printf("%d\t", frames[j]);
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Hits: %d\n", hits);

    return 0;
}
