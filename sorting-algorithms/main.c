#include "sorting.h"
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void selectAlgorithm(typeE v[], int n, char *algorithm) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    if (strcmp("selectionSort", algorithm) == 0) {
        selectionSort(v, 0, n - 1);
    }
    else if (strcmp("bubbleSort", algorithm) == 0) {
        bubbleSort(v, 0, n - 1);
    }
    else if (strcmp("insertionSort", algorithm) == 0) {
        insertionSort(v, 0, n - 1);
    }
    else if (strcmp("mergeSort", algorithm) == 0) {
        mergeSort(v, v, 0, n - 1);
    }
    else if (strcmp("quickSort", algorithm) == 0) {
        quickSort(v, 0, n - 1);
    }
    else if (strcmp("heapSort", algorithm) == 0) {
        heapSort(v, 0, n - 1);
    }
    gettimeofday(&end, NULL);
    printf("%s: %fseg\n", algorithm, (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6);
}

void randomVector(typeE v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = (float) (rand()) / (float) (RAND_MAX);
    }
}

int main() {
    printf("--------------------------------------------\n");
    printf("   Sorting Algorithms\n");
    printf("--------------------------------------------\n\n");

    int n;
    do {
        printf("Size of vector -> ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Creating vectors...\n");
    typeE *v = malloc(n * sizeof(typeE));
    if (v == NULL) {
        perror("malloc");
        exit(-1);
    }

    srand(time(NULL));
    randomVector(v, n);
    
    printf("Sorting...\n");
    selectAlgorithm(v, n, "bubbleSort");
    randomVector(v, n);
    selectAlgorithm(v, n, "selectionSort");
    randomVector(v, n);
    selectAlgorithm(v, n, "insertionSort");
    randomVector(v, n);
    selectAlgorithm(v, n, "heapSort");
    randomVector(v, n);
    selectAlgorithm(v, n, "mergeSort");
    randomVector(v, n);
    selectAlgorithm(v, n, "quickSort");

    return 0;
}